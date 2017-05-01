#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/FormattingChannel.h"
#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/PatternFormatter.h"
#include "Poco/SplitterChannel.h"
#include "clientdialog.h"
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QUrl>
#include <string>

namespace Ui {
class MainWindow;
}

class QNetworkReply;
class QCheckBox;
class QAuthenticator;
class QSslError;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void startRequest();
  void startPost(QJsonObject jWrite);
  std::string utf8_url_memory;

private slots:
  void on_button_open_ClientDialog_triggered();
  void httpRead();
  void driveFunctionCommand(const QJsonValue &Direction);
  void stopDriving();
  void on_pushButton_Forward_pressed();
  void on_pushButton_Forward_released();
  void on_pushButton_Stop_pressed();
  void on_pushButton_Backward_pressed();
  void on_pushButton_Backward_released();
  void on_pushButton_Left_pressed();
  void on_pushButton_Left_released();
  void on_pushButton_Right_pressed();
  void on_pushButton_Right_released();
  void on_pushButton_Stop_2_pressed();
  void on_pushButton_Spot_pressed();
  void on_pushButton_Clean_pressed();
  void on_pushButton_Dock_pressed();
  void on_pushButton_Forward_Left_pressed();
  void on_pushButton_Forward_Left_released();
  void on_pushButton_Forward_Right_pressed();
  void on_pushButton_Forward_Right_released();
  void on_pushButton_Backward_Left_pressed();
  void on_pushButton_Backward_Left_released();
  void on_pushButton_Backward_Right_pressed();
  void on_pushButton_Backward_Right_released();
  void on_pushButton_Spot_Man_clicked();
  void on_pushButton_Clean_Man_clicked();
  void on_pushButton_Dock_Man_clicked();

private:
  Ui::MainWindow *ui_;
  QUrl url_;
  QNetworkAccessManager qnam_;
  QNetworkReply *reply_;
  QByteArray response_data_;
  Poco::Logger &sLog_;
  bool httpRequestAborted_;
  int Wheel_Speed_Value_;
  int Brush_Speed_Value_;
};

#endif // MAINWINDOW_H
