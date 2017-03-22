#include "mainwindow.h"
#include "client.h"
#include "clientdialog.h"
#include "stdio.h"
#include "ui_mainwindow.h"
#include <QString>
#include <iostream>

bool checked = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->pushButton_auto_Off->setIcon(QIcon("://Images/switcht_off.png"));
  ui->pushButton_auto_Off->setIconSize(QSize(100, 150));
  ui->pushButton_auto_Off->setFixedSize(100, 150);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionServer_Connection_triggered() {
  ClientDialog clientdialog;
  clientdialog.setModal(true);
  clientdialog.exec();
}

void MainWindow::on_pushButton_auto_On_clicked() {
  std::cout << "clicked" << std::endl;
}

void MainWindow::on_pushButton_auto_Off_clicked() {
  checked = !checked;
  std::cout << "" << checked << std::endl;
  if (checked == false) {
    ui->pushButton_auto_Off->setIcon(QIcon("://Images/switcht_off.png"));
    std::cout << "false" << std::endl;
  }
  if (checked == true) {
    ui->pushButton_auto_Off->setIcon(QIcon("://Images/switches_on.png"));
    std::cout << "true" << std::endl;
  }
}

void MainWindow::on_pushButton_Stop_clicked() {}

void MainWindow::on_pushButton_Up_clicked() {}

void MainWindow::on_pushButton_Down_clicked() {}

void MainWindow::on_pushButton_Left_clicked() {}

void MainWindow::on_pushButton_Right_clicked() {}

void MainWindow::on_horizontalSlider_Roomba_Speed_valueChanged(int value) {}

void MainWindow::on_horizontalSlider_Brush_Speed_valueChanged(int value) {}
