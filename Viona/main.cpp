#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "plumbing.h"
#include "../util/helpers.h"
#include "sandbox.cpp"
int main(int argc, char *argv[])
{

//    manages the GUI application's control flow and main settings.

//    foo();
//    return 0;

    QGuiApplication app(argc, argv);

    qmlRegisterType<Plumbing>("plumbing", 0, 1, "Plumbing");

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
