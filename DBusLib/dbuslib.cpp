#include "dbuslib.h"
#include <QDebug>
DBusLib::DBusLib(QObject *parent) : QObject(parent)
{

}

DBusLib::DBusLib(QDBusInterface sysusersd)
{
    _sysusersd = &sysusersd;
}

QDBusInterface* DBusLib::connectToInterface(QString serviceName, QString path) const
{
    // find our remote
    QDBusInterface* qDBusInterface = new QDBusInterface(serviceName, path, serviceName, QDBusConnection::systemBus());
    if (!qDBusInterface->isValid()) {
        qInfo() << "error";
    }

    return qDBusInterface;
}

void DBusLib::setSysusersd(QDBusInterface iface)
{
    _sysusersd = &iface;
}

