#ifndef SERIALHANDLER_H
#define SERIALHANDLER_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray> // Ensure QByteArray is included

class SerialHandler : public QObject
{
    Q_OBJECT
public:
    explicit SerialHandler(QObject* parent = nullptr);

    Q_INVOKABLE void setPortName(const QString& portName);
    Q_INVOKABLE void setBaudRate(qint32 baudRate);
    Q_INVOKABLE void open();
    Q_INVOKABLE void close();

signals:
    void dataReceived(const QByteArray& data);

private slots:
    void handleReadyRead();

private:
    QSerialPort m_serialPort;
};

#endif // SERIALHANDLER_H
