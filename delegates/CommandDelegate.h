#ifndef COMMANDDELEGATE_H
#define COMMANDDELEGATE_H

#include <QStyledItemDelegate>

class CommandDelegate : public QStyledItemDelegate
{

public: // c-tors/d-tors
  explicit CommandDelegate(QObject *parent = nullptr);

  // QAbstractItemDelegate interface
public:
  virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
  virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
  virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;
  virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};

#endif // COMMANDDELEGATE_H
