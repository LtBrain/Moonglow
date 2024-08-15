#include "SerialHandler.h"
#include <QDebug>

SerialHandler::SerialHandler(QObject* parent)
    : QObject(parent)
{
    // Connect the readyRead signal to the handleReadyRead slot
    connect(&m_serialPort, &QSerialPort::readyRead, this, &SerialHandler::handleReadyRead);
}

void SerialHandler::setPortName(const QString& portName)
{
    // Set the name of the serial port
    m_serialPort.setPortName(portName);
}

void SerialHandler::setBaudRate(qint32 baudRate)
{
    // Set the baud rate for the serial communication
    m_serialPort.setBaudRate(baudRate);
}

void SerialHandler::open()
{
    // Attempt to open the serial port in read-only mode
    if (!m_serialPort.open(QIODevice::ReadOnly)) {
        // If it fails, log the error using qWarning
        qWarning() << "Failed to open port:" << m_serialPort.errorString();
    }
}

void SerialHandler::close()
{
    // Close the serial port
    m_serialPort.close();
}

void SerialHandler::handleReadyRead()
{
    // Read all available data from the serial port
    QByteArray data = m_serialPort.readAll();

    // Emit the dataReceived signal to notify other parts of the application
    emit dataReceived(data);
}
