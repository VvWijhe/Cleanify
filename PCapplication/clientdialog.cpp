#include "clientdialog.h"
#include "mainwindow.h"
#include "stdio.h"
#include "ui_clientdialog.h"
#include <QString>
#include <iostream>

using namespace Poco;

std::string connected_to_url;

ClientDialog::ClientDialog(QWidget *parent)
    : QDialog(parent), ui_(new Ui::ClientDialog),
      sLog_(Logger::get("ClientDialog")) {
    ui_->setupUi(this);
    ui_->lineEdit->setText(QString::fromStdString(connected_to_url));
}

ClientDialog::~ClientDialog() { delete ui_; }

void ClientDialog::on_OK_clicked() {
    utf8_url = ui_->lineEdit->text().toUtf8().constData();
    connected_to_url = ui_->lineEdit->text().toUtf8().constData();
    sLog_.information("URL: " + utf8_url + " has been input");
    sLog_.trace("Pressed Ok");
    this->close();
}

void ClientDialog::on_Cancel_clicked() {
    sLog_.trace("Pressed Cancel");
    this->close();
}
