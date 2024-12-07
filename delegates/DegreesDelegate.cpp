#include "DegreesDelegate.h"
#include "delegates/DegreesDelegate.h"
#include "delegates/DegreesWidget.h"

#include <QTextOption>
#include <QPainter>
#include <QStringBuilder>

DegreesDelegate::DegreesDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

void DegreesDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant data = index.data();
    if (data.canConvert<int>()) {
        QString bits = "0x" % QString::number(data.toInt(), 16).toUpper();
        QTextOption opts(Qt::AlignCenter);
        painter->drawText(option.rect, bits, opts);
        return;
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QWidget *DegreesDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    int data = index.data().toInt();
    DegreesWidget* degreesWidget = new DegreesWidget(data, parent);
    return degreesWidget;
}

void DegreesDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    DegreesWidget* dgrW = qobject_cast<DegreesWidget*>(editor);
    if (dgrW) {
        int data = dgrW->degress();
        model->setData(index, data);
    }
}

void DegreesDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    DegreesWidget* dgrW = qobject_cast<DegreesWidget*>(editor);
    if (dgrW) {
        const QRect& rect = option.rect;
        QPoint tL = dgrW->parentWidget()->mapToGlobal(rect.topLeft());
        dgrW->move(tL.x(), tL.y() + rect.height());
    } else {
        QStyledItemDelegate::updateEditorGeometry(editor, option, index);
    }
}
