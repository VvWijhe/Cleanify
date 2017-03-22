#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clientdialog.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:

  void on_actionServer_Connection_triggered();

  void on_pushButton_auto_On_clicked();

  void on_pushButton_auto_Off_clicked();

  void on_pushButton_Stop_clicked();

  void on_pushButton_Up_clicked();

  void on_pushButton_Down_clicked();

  void on_pushButton_Left_clicked();

  void on_pushButton_Right_clicked();

  void on_horizontalSlider_Roomba_Speed_valueChanged(int value);

  void on_horizontalSlider_Brush_Speed_valueChanged(int value);

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
