#ifndef DEGREESWIDGET_H
#define DEGREESWIDGET_H

#include <QWidget>

namespace Ui {
class DegreesWidget;
}

class DegreesWidget : public QWidget
{
    Q_OBJECT

public: // c-tors/d-tors
    explicit DegreesWidget(QWidget *parent = 0);
    DegreesWidget(int degrees, QWidget *parent = 0);
    ~DegreesWidget();

public: // functions
    int degress() const;
    void setDegrees(int degrees);

private slots:
    void on_dial_valueChanged(int value);

private: // fields
    Ui::DegreesWidget *ui;

private: // functions
  void updateControls();
  void setupWidget();

};

#endif // DEGREESWIDGET_H
