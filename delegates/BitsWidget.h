#ifndef BITSWIDGET_H
#define BITSWIDGET_H

#include <QWidget>

namespace Ui {
class BitsWidget;
}

class BitsWidget : public QWidget
{
    Q_OBJECT

public: // c-tors/d-tors
    explicit BitsWidget(QWidget *parent = 0);
    BitsWidget(int bitsMask, QWidget *parent = 0);
    ~BitsWidget();

public: // functions
    void setBitsMask(int mask);
    int bitsMask() const;

private: // fields
    Ui::BitsWidget *ui;    

private: // functions
  void setupWidget();

};

#endif // BITSWIDGET_H
