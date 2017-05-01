#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/FormattingChannel.h"
#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/PatternFormatter.h"
#include "Poco/SplitterChannel.h"
#include <QDialog>

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog {
  Q_OBJECT

public:
  explicit ClientDialog(QWidget *parent = 0);
  ~ClientDialog();
  std::string utf8_url;

private slots:
  void on_OK_clicked();
  void on_Cancel_clicked();

private:
  Ui::ClientDialog *ui_;
  Poco::Logger &sLog_;
};

#endif // CLIENTDIALOG_H
