#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <model/variantmaptablemodel.h>
#include <QQuickView>
#include<QQmlContext>
#include <listModel/localuser.h>
#include <listModel/localuserlistmodel.h>
#include <UserTableModel/localusertablemodel.h>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //qmlRegisterType<LocalUserListModel>("LocalUserListModel", 1, 0, "LocalUserListModel");
    qmlRegisterType<LocalUser>("LocalUser", 1, 0, "LocalUser");
    //qmlRegisterType<LocalUserTableModel>("LocalUserTableModel", 1, 0, "TestModel");

    LocalUserListModel model;
    engine.rootContext()->setContextProperty("userModel", &model);

    return app.exec();
}
