#include "dbuslib.h"
#include <QDebug>

DBusLib::DBusLib(QObject *parent) : QObject(parent)
{
    _sysusersd = connectToInterface("org.freedesktop.hostname1", "/org/freedesktop/hostname1");
}

DBusLib::DBusLib(QDBusInterface* sysusersd)
{
    _sysusersd = sysusersd;
}

DBusLib::~DBusLib()
{
    delete _sysusersd;
}

QDBusInterface* DBusLib::connectToInterface(QString serviceName, QString path)
{
    // find our remote
    QDBusInterface* iface = new QDBusInterface(serviceName, path, serviceName, QDBusConnection::sessionBus(), this);
    if (!iface->isValid()) {
        qInfo() << "error";
    }

    return iface;
}

void DBusLib::setSysusersd(QDBusInterface* iface)
{
    _sysusersd = iface;
}

QDBusInterface *DBusLib::getSysusersd()
{
    return _sysusersd;
}

