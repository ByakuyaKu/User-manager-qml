#include "localuser.h"
#include <QDebug>
//LocalUser::LocalUser()
//{

//}

LocalUser::LocalUser(QObject *parent) : QObject(parent)
{

}

LocalUser::LocalUser(const QString &RegistratorName, const QString &UID, const QString &GID, const QString &FullName, const QString &HomeDir, const QString &LoginEngine)
{
    _UID = UID;
    _GID = GID;
    _RegistratorName = RegistratorName;
    _FullName = FullName;
    _HomeDir = HomeDir;
    _LoginEngine = LoginEngine;
}

QString LocalUser::UID() const
{
    return _UID;
}

QString LocalUser::GID() const
{
    return _GID;
}

QString LocalUser::RegistratorName() const
{
    return _RegistratorName;
}

QString LocalUser::FullName() const
{
    return _FullName;
}

QString LocalUser::HomeDir() const
{
    return _HomeDir;
}

QString LocalUser::LoginEngine() const
{
    return _LoginEngine;
}

void LocalUser::setUid(QString uid)
{
    if (_UID == uid) {
            return;
        }

        _UID = uid;

        emit uidChanged(_UID);
}

void LocalUser::setGid(QString gid)
{
    if (_GID == gid) {
            return;
        }

        _GID = gid;

        emit gidChanged(_GID);
}

void LocalUser::setRegistratorName(QString registratorName)
{
    if (_RegistratorName == registratorName) {
            return;
        }

        _RegistratorName = registratorName;

        emit uidChanged(_RegistratorName);
}

void LocalUser::setFullName(QString fullName)
{
    if (_FullName == fullName) {
            return;
        }

        _FullName = fullName;

        emit uidChanged(_FullName);
}

void LocalUser::setHomeDir(QString homeDir)
{
    if (_HomeDir == homeDir) {
            return;
        }

        _HomeDir = homeDir;

        emit uidChanged(_HomeDir);
}

void LocalUser::setLoginEngine(QString loginEngine)
{
    if (_LoginEngine == loginEngine) {
            return;
        }

        _LoginEngine = loginEngine;

        emit uidChanged(_LoginEngine);
}

QList<LocalUser *> LocalUser::getLocalUsers()
{
    QStringList unparsedLocalUsers = getUnparsedLocalUsers();

    QList<LocalUser*> parsedLocalUsers = ParseLocalUsers(unparsedLocalUsers);

    return parsedLocalUsers;
}

QStringList LocalUser::getUnparsedLocalUsers()
{
    QProcess clp;
    QStringList usersList;

    clp.start("less", QStringList() << "/etc/passwd");

    if (!clp.waitForStarted())
        return usersList;

    if (!clp.waitForFinished())
        return usersList;

    QString result = clp.readAll();
    QStringRef res = &result;

    usersList = result.split(QLatin1Char('\n'));

    return usersList;
}

QList<LocalUser *> LocalUser::ParseLocalUsers(QStringList &usersList)
{
    QList<LocalUser*> parsedUsersList;
    for(int i = 0; i < usersList.length()-1; i++)
    {
        QStringList userInfo = usersList[i].split(QLatin1Char(':'));
        LocalUser *curUser = new LocalUser(userInfo[0], userInfo[2], userInfo[3], userInfo[4], userInfo[5], userInfo[6]);
        parsedUsersList.append(curUser);

        //qInfo() << (curUser->HomeDir() + " | " + curUser->FullName() + " | " + curUser->GID() + " | " + curUser->LoginEngine() + curUser->UID() + " | " + " || ");
    }
    //qInfo() << "parsedUsersList.length()";
    return parsedUsersList;
}
