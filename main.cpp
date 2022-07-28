#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <model/variantmaptablemodel.h>
#include <QQuickView>
#include<QQmlContext>
#include <listModel/localuser.h>
#include <listModel/localuserlistmodel.h>
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


    qmlRegisterType<LocalUserListModel>("LocalUserListModel", 1, 0, "LocalUserListModel");
    qmlRegisterType<LocalUser>("LocalUser", 1, 0, "LocalUser");

    LocalUserListModel model;
    engine.rootContext()->setContextProperty("modelu", &model);

    VariantMapTableModel tableModel;
    tableModel.registerColumn(new SimpleColumn("uid"));
    //tableModel.registerColumn(new SimpleColumn("name"));

    QVariantMap user1;
    user1.insert("UID", 1);
    //user1.insert("Name", "user1");
    tableModel.addRow(user1);

    QVariantMap user2;
    user1.insert("UID", 12);
    //user1.insert("Name", "user2");
    tableModel.addRow(user2);

    //QQmlContext *context = engine.rootContext();
    engine.rootContext()->setContextProperty("tableModel", &tableModel);


    return app.exec();
}
