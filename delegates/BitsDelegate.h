#ifndef BITSDELEGATE_H
#define BITSDELEGATE_H


#include <QStyledItemDelegate>


class BitsDelegate : public QStyledItemDelegate
{
public: // c-tors/d-tors
    explicit BitsDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // BITSDELEGATE_H
