#include "mainwindow.h"
#include "clientdialog.h"
#include "ui_mainwindow.h"
#include <QByteArray>
#include <QJsonObject>
#include <QLabel>
#include <QString>
#include <QUrl>
#include <QtNetwork>
#include <iostream>
#include <sstream>
#include <string>

using namespace Poco;

std::string url_page, url_page_post, url_page_request;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow),
      sLog_(Logger::get("MainWindow")) {
  ui_->setupUi(this);
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::on_button_open_ClientDialog_triggered() {
  sLog_.trace("ClientDialog opened");
  ClientDialog clientdialog;
  clientdialog.setModal(true);
  clientdialog.utf8_url = url_page;
  clientdialog.exec();
  url_page = clientdialog.utf8_url;
  sLog_.trace("ClientDialog closed");

  /* STATUS BAR MESSAGE */
  ui_->statusBar->showMessage(
      QString::fromStdString(("Entered URL: " + url_page)));
  url_page_post = url_page + "/control";
  url_page_request = url_page + "/status";
}

void MainWindow::startRequest() {
  url_ = QUrl(url_page_request.c_str());
  httpRequestAborted_ = false;
  reply_ = qnam_.get(QNetworkRequest(url_));
  connect(reply_, &QIODevice::readyRead, this, &MainWindow::httpRead);
}

void MainWindow::startPost(QJsonObject jWrite) {
  QString jsonString;
  // Send data server
  url_ = QUrl(url_page_post.c_str());
  QNetworkRequest request(url_);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  reply_ = qnam_.post(request, QJsonDocument(jWrite).toJson());
  while (!reply_->isFinished()) {
    qApp->processEvents();
  }
  // Server response
  response_data_ = reply_->readAll();
  QJsonDocument jsave = QJsonDocument::fromJson(response_data_);
  reply_->deleteLater();
  jsonString = jsave.toJson(QJsonDocument::Indented);
  sLog_.information("Response: " + jsonString.toStdString());
}

void MainWindow::httpRead() {
  QString body(reply_->readAll());
  sLog_.debug("Data " + body.toStdString());
}

void MainWindow::driveFunctionCommand(const QJsonValue &direction) {
  QJsonObject jWrite;
  Wheel_Speed_Value_ = ui_->horizontalSlider_Wheel_Speed->value();
  Brush_Speed_Value_ = ui_->horizontalSlider_Brush_Speed->value();
  jWrite.insert("session", "PC");
  jWrite.insert("direction", direction);
  // jWrite.insert("wheel_speed", (Wheel_Speed_Value_/100));
  // jWrite.insert("brush_speed", (Brush_Speed_Value_/100));
  startPost(jWrite);
  sLog_.debug("wheel_speed: " + std::to_string(Wheel_Speed_Value_ / 100) +
              ", brush_speed: " + std::to_string(Brush_Speed_Value_ / 100));
}

void MainWindow::stopDriving() {
  QJsonObject jWrite;
  jWrite.insert("session", "PC");
  jWrite.insert("direction", "stop");
  // jWrite.insert("wheel_speed", 0);
  // jWrite.insert("brush_speed", 0);
  startPost(jWrite);
  sLog_.trace("Function stopDriving()");
}

void MainWindow::on_pushButton_Stop_pressed() {
  stopDriving();
  Server_Exit();
  ui_->horizontalSlider_Brush_Speed->setValue(0);
  ui_->horizontalSlider_Wheel_Speed->setValue(0);
  sLog_.trace("Pressed Stop_1");
}

void MainWindow::on_pushButton_Forward_pressed() {
  driveFunctionCommand("forward");
  sLog_.trace("Pressed forward");
}
void MainWindow::on_pushButton_Backward_pressed() {
  driveFunctionCommand("backward");
  sLog_.trace("Pressed backward");
}
void MainWindow::on_pushButton_Left_pressed() {
  driveFunctionCommand("left");
  sLog_.trace("Pressed left");
}
void MainWindow::on_pushButton_Right_pressed() {
  driveFunctionCommand("right");
  sLog_.trace("Pressed right");
}
void MainWindow::on_pushButton_Forward_Left_pressed() {
  driveFunctionCommand("forward_left");
  sLog_.trace("Pressed forward-left");
}
void MainWindow::on_pushButton_Forward_Right_pressed() {
  driveFunctionCommand("forward_right");
  sLog_.trace("Pressed rorward-right");
}
void MainWindow::on_pushButton_Backward_Left_pressed() {
  driveFunctionCommand("backward_left");
  sLog_.trace("Pressed backward-left");
}
void MainWindow::on_pushButton_Backward_Right_pressed() {
  driveFunctionCommand("backward_right");
  sLog_.trace("Pressed backward-right");
}

void MainWindow::on_pushButton_Stop_2_pressed() {
  stopDriving();
  Server_Exit();
  sLog_.trace("Pressed Stop_2");
}

void MainWindow::on_pushButton_Spot_pressed() {
  QJsonObject jWrite;
  sLog_.trace("Pressed Spot");
  stopDriving();
  jWrite.insert("session", "PC");
  jWrite.insert("pre-commands", "spot");
  startPost(jWrite);
}

void MainWindow::on_pushButton_Clean_pressed() {
  QJsonObject jWrite;
  sLog_.trace("Pressed Clean-Man");
  stopDriving();
  jWrite.insert("session", "PC");
  jWrite.insert("pre-commands", "clean-man");
  startPost(jWrite);
}

void MainWindow::on_pushButton_Dock_pressed() {
  QJsonObject jWrite;
  sLog_.trace("Pressed Dock-Man");
  stopDriving();
  jWrite.insert("session", "PC");
  jWrite.insert("pre-commands", "dock-man");
  startPost(jWrite);
}

void MainWindow::on_pushButton_Spot_Man_clicked() {
  QJsonObject jWrite;
  sLog_.trace("Pressed Spot-Man");
  stopDriving();
  jWrite.insert("session", "PC");
  jWrite.insert("pre-commands", "spot-man");
  startPost(jWrite);
}

void MainWindow::on_pushButton_Clean_Man_clicked() {
  QJsonObject jWrite;
  sLog_.trace("Pressed Clean-Man");
  stopDriving();
  jWrite.insert("session", "PC");
  jWrite.insert("pre-commands", "clean-man");
  startPost(jWrite);
}

void MainWindow::on_pushButton_Dock_Man_clicked() {
  QJsonObject jWrite;
  sLog_.trace("Pressed Dock-Man");
  stopDriving();
  jWrite.insert("session", "PC");
  jWrite.insert("pre-commands", "dock-man");
  startPost(jWrite);
}

void MainWindow::on_pushButton_Forward_released() { stopDriving(); }
void MainWindow::on_pushButton_Backward_released() { stopDriving(); }
void MainWindow::on_pushButton_Left_released() { stopDriving(); }
void MainWindow::on_pushButton_Right_released() { stopDriving(); }
void MainWindow::on_pushButton_Forward_Left_released() { stopDriving(); }
void MainWindow::on_pushButton_Forward_Right_released() { stopDriving(); }
void MainWindow::on_pushButton_Backward_Left_released() { stopDriving(); }
void MainWindow::on_pushButton_Backward_Right_released() { stopDriving(); }

void MainWindow::Server_Exit() {
  QJsonObject jWrite;
  jWrite.insert("exit", "true");
  QString jsonString;
  // Send data server
  url_ = QUrl(url_page_post.c_str());
  QNetworkRequest request(url_);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  reply_ = qnam_.post(request, QJsonDocument(jWrite).toJson());
  while (!reply_->isFinished()) {
    qApp->processEvents();
  }
  // Server response
  response_data_ = reply_->readAll();
  QJsonDocument jsave = QJsonDocument::fromJson(response_data_);
  reply_->deleteLater();
  jsonString = jsave.toJson(QJsonDocument::Indented);
  sLog_.information("Response: " + jsonString.toStdString());
}

// Needed for parsing:
// nlohmann::json jRead;
// std::stringstream ss;
// jRead = jRead.parse(body.toStdString());
// ss << "Geparsed: " << jRead["Battery"];
// std::cout << "Geparsed: " << jRead["Battery"] << std::endl;
// sLog.information(ss.str().c_str());
