#ifndef SERIAL_H
#define SERIAL_H

#include <QtSerialPort/QSerialPort>
#include <memory>
#include <iostream>
#include <QObject>
#include <queue>
#include <mutex>
#include <QDebug>

class Serial: public QObject {
    Q_OBJECT
public:
    Serial() {
        _serial = std::make_shared<QSerialPort>();

        connect(_serial.get(), &QSerialPort::readyRead, this, &Serial::readyRead);

        _serial->setPortName("/dev/tnt1");
        _serial->setBaudRate(QSerialPort::Baud115200);
        _serial->setDataBits(QSerialPort::Data8);
        _serial->setParity(QSerialPort::NoParity);
        _serial->setStopBits(QSerialPort::OneStop);
        _serial->setFlowControl(QSerialPort::NoFlowControl);
    }

    ~Serial() {
        _serial->close();
    }

    int openPort() {
        return _serial->open(QIODevice::ReadWrite) ? 1 : -1;
    }

    QByteArray getBuffer() {
        if(_serialBuffer.size() == 0) {
            return QByteArray();
        }

        auto tmp = _serialBuffer.front();
        _serialBuffer.pop();
        return tmp;
    }

    void send(const QByteArray& data) {
        _serial->write(data);
    }

public slots:
    void readyRead() {
//        QByteArray data = _serial->readAll();

//        qDebug() << data;

        _serialBuffer.push(_serial->readAll());
    }

private:
    std::queue<QByteArray> _serialBuffer;
    std::shared_ptr<QSerialPort> _serial;
};

#endif // SERIAL_H
