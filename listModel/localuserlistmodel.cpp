#include "localuserlistmodel.h"
#include <QAbstractListModel>
//LocalUserListModel::LocalUserListModel()
//{

//}

LocalUserListModel::LocalUserListModel(QObject *parent) : QObject(parent)
{
//    LocalUser *user = new LocalUser(this);
//        user->setProperty("UID", "1");
//        user->setProperty("GID", "2");
//        user->setProperty("FullName", "eldest");
//        user->setProperty("RegistratorName", "Dir");
//        user->setProperty("HomeDir", "Dir");
//        user->setProperty("LoginEngine", "33");
        LocalUser u;
        QList<LocalUser*> users = u.getLocalUsers();
        _localUsers << users;
        //_localUsers << user;
        //_localUsers << user;
}

//QHash<int, QByteArray> LocalUserListModel::roleNames() const
//{
//    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
//        roles[ColorRole] = "color";
//        roles[TextRole] = "text";

//        return roles;
//}

QQmlListProperty<LocalUser> LocalUserListModel::data()
{
    return QQmlListProperty<LocalUser>(static_cast<QObject *>(this), static_cast<void *>(&_localUsers),
                                         &LocalUserListModel::appendData, &LocalUserListModel::countData,
                                         &LocalUserListModel::atData, &LocalUserListModel::clearData);
}

void LocalUserListModel::add(LocalUser *user)
{
//    LocalUser *user = new LocalUser(this);
//        user->setProperty("color", "skyblue");
//        user->setProperty("text", "new");
//        _localUsers.append(user);

    _localUsers.append(user);
        emit dataChanged();
}

void LocalUserListModel::appendData(QQmlListProperty<LocalUser> *list, LocalUser *value)
{
    QList<LocalUser*> *data = static_cast<QList<LocalUser*> *>(list->data);
        data->append(value);
}

int LocalUserListModel::countData(QQmlListProperty<LocalUser> *list)
{
    QList<LocalUser*> *data = static_cast<QList<LocalUser*> *>(list->data);
        return data->count();
}

LocalUser *LocalUserListModel::atData(QQmlListProperty<LocalUser> *list, int index)
{
    QList<LocalUser*> *data = static_cast<QList<LocalUser*> *>(list->data);
        return data->at(index);
}

void LocalUserListModel::clearData(QQmlListProperty<LocalUser> *list)
{
    QList<LocalUser*> *data = static_cast<QList<LocalUser*> *>(list->data);
        qDeleteAll(data->begin(), data->end());
        data->clear();
}
