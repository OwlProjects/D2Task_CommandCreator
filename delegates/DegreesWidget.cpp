#include "DegreesWidget.h"
#include "ui_DegreesWidget.h"

DegreesWidget::DegreesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DegreesWidget)
{
    ui->setupUi(this);
    setupWidget();
}

DegreesWidget::DegreesWidget(int degrees, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DegreesWidget)
{
    ui->setupUi(this);
    setupWidget();
    setDegrees(degrees);
}

DegreesWidget::~DegreesWidget()
{
    delete ui;
}

int DegreesWidget::degress() const
{
    return ui->dial->value();
}

void DegreesWidget::setDegrees(int degrees)
{
    ui->dial->setValue(degrees);
    updateControls();
}

void DegreesWidget::updateControls()
{
    ui->lineEdit->setText(QString::number(ui->dial->value()));
}

void DegreesWidget::setupWidget()
{
    setWindowFlags(Qt::Popup);
}

void DegreesWidget::on_dial_valueChanged(int value)
{
    Q_UNUSED(value)
    updateControls();
}
