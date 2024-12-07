#include "BitsDelegate.h"
#include "BitsWidget.h"

#include <QTextOption>
#include <QPainter>
#include <QStringBuilder>

BitsDelegate::BitsDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

void BitsDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
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

QWidget *BitsDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    int data = index.data().toInt();
    BitsWidget* bitsWidget = new BitsWidget(data, parent);
    return bitsWidget;
}



void BitsDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    BitsWidget* bitsw = qobject_cast<BitsWidget*>(editor);
    if (bitsw) {
        int data = bitsw->bitsMask();
        model->setData(index, data);
    }
}

void BitsDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    BitsWidget* bitsw = qobject_cast<BitsWidget*>(editor);
    if (bitsw) {
        const QRect& rect = option.rect;
        QPoint tL = bitsw->parentWidget()->mapToGlobal(rect.topLeft());
        bitsw->move(tL.x(), tL.y() + rect.height());
    } else {
        QStyledItemDelegate::updateEditorGeometry(editor, option, index);
    }
}
