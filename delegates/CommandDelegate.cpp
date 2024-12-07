#include "CommandDelegate.h"

#include <QComboBox>
#include <QTextOption>
#include <QPainter>


CommandDelegate::CommandDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

void CommandDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QVariant data = index.data();
  if (data.canConvert<QString>()) {
      QString cmd = data.toString();
      QTextOption opts(Qt::AlignCenter);
      painter->drawText(option.rect, cmd, opts);
      return;
  } else {
    QStyledItemDelegate::paint(painter, option, index);
  }
}

QWidget *CommandDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  Q_UNUSED(option)
  QString data = index.data().toString();
  QComboBox* cb = new QComboBox(parent);
  cb->setStyleSheet("QComboBox QAbstractItemView {"
                      "min-width: 150px;"
                    "}");
  cb->addItem("0x01 (Выдача настроек)", "0x01");
  cb->addItem("0x02 (Чтение настроек)", "0x02");
  cb->setCurrentIndex(cb->findData(data));
  return cb;
}

void CommandDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QComboBox* cb = qobject_cast<QComboBox*>(editor);
  if (cb) {
    QVariant data = index.data();
    int index = cb->findData(data);
    if (index >= 0) {
      cb->setCurrentIndex(index);
    }
  }
}

void CommandDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QComboBox* cb = qobject_cast<QComboBox*>(editor);
  if (cb) {
    QVariant data = cb->currentData();
    model->setData(index, data);
  }
}

