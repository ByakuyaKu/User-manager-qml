#ifndef DBUSLIB_H
#define DBUSLIB_H

#include <QObject>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusConnection>

class DBusLib : public QObject
{
    Q_OBJECT
public:
    DBusLib(QObject *parent = nullptr);

    DBusLib(QDBusInterface sysusersd);

    QDBusInterface* connectToInterface(QString serviceName, QString path) const;
    void setSysusersd(QDBusInterface iface);

private:
    QDBusInterface* _sysusersd;
};

#endif // DBUSLIB_H
