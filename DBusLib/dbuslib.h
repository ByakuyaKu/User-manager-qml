#ifndef DBUSLIB_H
#define DBUSLIB_H

#include <QObject>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusConnection>
#define SERVICE_NAME            "org.example.QtDBus.PingExample"

class DBusLib : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QDBusInterface* _sysusersd READ getSysusersd WRITE setSysusersd)
public:
    DBusLib(QObject *parent = nullptr);

    DBusLib(QDBusInterface* sysusersd);

    ~DBusLib();

    QDBusInterface* connectToInterface(QString serviceName, QString path);
    void setSysusersd(QDBusInterface* iface);
    QDBusInterface* getSysusersd();

private:
    QDBusInterface* _sysusersd;
};

#endif // DBUSLIB_H
