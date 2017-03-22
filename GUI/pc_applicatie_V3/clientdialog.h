#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H
#include <QDialog>

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog {
  Q_OBJECT

public:
  explicit ClientDialog(QWidget *parent = 0);
  ~ClientDialog();

private slots:
  void on_lineEdit_returnPressed();

private:
  Ui::ClientDialog *ui;
};

#endif // CLIENTDIALOG_H
