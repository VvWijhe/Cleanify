#include "Poco/AsyncChannel.h"
#include "Poco/AutoPtr.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/FormattingChannel.h"
#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/PatternFormatter.h"
#include "Poco/SplitterChannel.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>

using namespace Poco;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  AutoPtr<SplitterChannel> splitterChannel(new SplitterChannel());

  AutoPtr<Channel> consoleChannel(new ConsoleChannel());
  AutoPtr<Channel> fileChannel(new FileChannel("Logger.log"));
  splitterChannel->addChannel(consoleChannel);
  splitterChannel->addChannel(fileChannel);

  AutoPtr<Channel> formattingChannel(new FormattingChannel(
      new PatternFormatter("%d-%m-%Y %L%H:%M:%S %s %p: %t"), splitterChannel));
  Logger::create("MainWindow", formattingChannel, Message::PRIO_DEBUG);
  Logger::create("ClientDialog", formattingChannel, Message::PRIO_DEBUG);
  MainWindow w;
  w.move(QApplication::desktop()->screen()->rect().center() -
         w.rect().center());
  w.show();
  w.setWindowTitle("PC-Applicatie");
  return a.exec();
}

// Poco logger *tip
// http://date.jsontest.com/
