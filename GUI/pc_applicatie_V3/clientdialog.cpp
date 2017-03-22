#include "clientdialog.h"
#include "client.h"
#include "stdio.h"
#include "ui_clientdialog.h"
#include <QString>
#include <iostream>

#define ARGC_SIZE 2

std::string utf8_text;

ClientDialog::ClientDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::ClientDialog) {
  ui->setupUi(this);
}

ClientDialog::~ClientDialog() { delete ui; }

void ClientDialog::on_lineEdit_returnPressed() {
  QString variable = ui->lineEdit->text();
  utf8_text = variable.toUtf8().constData();
  std::cout << "" << utf8_text << std::endl;
  char *cmd[] = {0, (char *)utf8_text.c_str()};
  client_connect(ARGC_SIZE, cmd);
  client_write("connected");
  client_recv();
  client_disconnect();
}
