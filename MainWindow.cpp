#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "delegates/CommandDelegate.h"
#include "delegates/BitsDelegate.h"
#include "delegates/DegreesDelegate.h"
#include <QStringBuilder>


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->tableWidgetCommand->setRowCount(1);
  ui->tableWidgetCommand->setColumnCount(3);
  ui->tableWidgetCommand->setHorizontalHeaderLabels({"КОП", "Флаги", "Угол"});
  ui->tableWidgetCommand->setItem(0, 0, new QTableWidgetItem("0x01"));
  ui->tableWidgetCommand->setItem(0, 1, new QTableWidgetItem("12"));
  ui->tableWidgetCommand->setItem(0, 2, new QTableWidgetItem("90"));

  auto cmdDlgt = new CommandDelegate(ui->tableWidgetCommand);
  cmdDlgt->setObjectName("cmdDlgt");
  ui->tableWidgetCommand->setItemDelegateForColumn(0, cmdDlgt);

  auto bitsDlgt = new BitsDelegate(ui->tableWidgetCommand);
  bitsDlgt->setObjectName("bitsDlgt");
  ui->tableWidgetCommand->setItemDelegateForColumn(1, bitsDlgt);

  auto dgrDlgt = new DegreesDelegate(ui->tableWidgetCommand);
  dgrDlgt->setObjectName("dgrDlgt");
  ui->tableWidgetCommand->setItemDelegateForColumn(2, dgrDlgt);
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_pushButtonAddCommand_clicked()
{
    QString byte0 = QString("%1")
            .arg(ui->tableWidgetCommand->item(0, 0)->data(Qt::DisplayRole).toString());
    QString byte1 = " 0x" % QString("%1")
            .arg(ui->tableWidgetCommand->item(0, 1)->data(Qt::DisplayRole).toInt(), 2, 16, QLatin1Char('0')).toUpper();
    QString byte2 = " 0x" % QString("%1")
            .arg(ui->tableWidgetCommand->item(0, 2)->data(Qt::DisplayRole).toInt(), 2, 16, QLatin1Char('0')).toUpper();
    ui->listWidgetCommands->addItem(byte0 % byte1 % byte2);
}
