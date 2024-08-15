#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "SerialHandler.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    // Create the QML application engine
    QQmlApplicationEngine engine;

    // Create an instance of SerialHandler
    SerialHandler serialHandler;

    // Expose the SerialHandler instance to QML
    engine.rootContext()->setContextProperty("serialHandler", &serialHandler);

    // Load the main QML file
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
