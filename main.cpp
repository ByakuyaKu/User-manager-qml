#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <listModel/localuser.h>
#include <listModel/localuserlistmodel.h>
#include <DBusLib/dbuslib.h>
#include <groupsTreeModel/treemodel.h>
#include <QFile>


#include <QtDBus/QtDBus>
#include <QProcess>
//#include <Qt5AccountsService/Qt5AccountsService>
#include <QtCore/QDebug>
//#include <Qt5AccountsService/AccountsManager>
//#include <Qt5AccountsService/UserAccount>
//#include <QtDBus/QDBusConnection>
//#include <QtDBus/QDBusConnectionInterface>
//#include <QtDBus/QDBusServiceWatcher>
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

    qmlRegisterType<LocalUser>("LocalUser", 1, 0, "LocalUser");
    LocalUserListModel model;
    engine.rootContext()->setContextProperty("userModel", &model);

    qmlRegisterType<LocalUser>("LocalUser", 1, 0, "LocalUser");
    qmlRegisterType<LocalUser>("TreeItem", 1, 0, "TreeItem");
    //qmlRegisterType<LocalUser>("QtAccountsService", 1, 0, "AccountsManager");
    //qmlRegisterType<LocalUser>("QtAccountsService::UserAccount", 1, 0, "UserAccount");
//QtAccountsService::AccountsManager *manager = new QtAccountsService::AccountsManager();
//const QtAccountsService::UserAccountList list;
//for (QtAccountsService::UserAccount *account : list)
    //qInfo() << account->realName() << account->userName();
//manager->listCachedUsers();


    //QDBusConnection::systemBus().registerObject("/", &app, QDBusConnection::ExportAllContents);
    //QtAccountsService::AccountsManager *manager = new QtAccountsService::AccountsManager();
    //app.connect(manager, &QtAccountsService::AccountsManager::listCachedUsersFinished, &app, [](const QtAccountsService::UserAccountList &list) {
    //QtAccountsService::UserAccountList list;
        //for (QtAccountsService::UserAccount *account : list)
    //QtAccountsService::UserAccount *account;
            //qInfo() << account->realName() << account->userName();
        //QCoreApplication::quit();
    //});

    qmlRegisterType<DBusLib>("DBusLib", 1, 0, "DBusLib");
    DBusLib DBusLib;
    engine.rootContext()->setContextProperty("DBusLib", &DBusLib);
    engine.load(url);

    //qmlRegisterType<DBusLib>("DBusLib", 1, 0, "DBusLib");

    //engine.rootContext()->setContextProperty("c", &ccc);
    //qmlRegisterType<LocalUserListModel>("LocalUserListModel", 1, 0, "LocalUserListModel");
    //qmlRegisterType<LocalUserTableModel>("LocalUserTableModel", 1, 0, "TestModel");


    return app.exec();
}
