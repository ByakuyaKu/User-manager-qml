#ifndef LOCALUSER_H
#define LOCALUSER_H

#include <QObject>
#include <QProcess>
class LocalUser : public QObject
{
    Q_PROPERTY(QString UID READ UID WRITE setUid NOTIFY uidChanged)
    Q_PROPERTY(QString GID READ GID WRITE setGid NOTIFY gidChanged)
    Q_PROPERTY(QString RegistratorName READ RegistratorName WRITE setRegistratorName NOTIFY registratorNameChanged)
    Q_PROPERTY(QString FullName READ FullName WRITE setFullName NOTIFY fullNameChanged)
    Q_PROPERTY(QString HomeDir READ HomeDir WRITE setHomeDir NOTIFY homeDirChanged)
    Q_PROPERTY(QString LoginEngine READ LoginEngine WRITE setLoginEngine NOTIFY loginEngineChanged)

    Q_OBJECT
public:
    LocalUser(QObject *parent = nullptr);

    LocalUser(const QString &_RegistratorName, const QString &_UID, const QString &_GID, const  QString &_FullName, const QString &_HomeDir, const QString &_LoginEngine);

    QString UID() const;
    QString GID() const;
    QString RegistratorName() const;
    QString FullName() const;
    QString HomeDir() const;
    QString LoginEngine() const;

    void setUid(QString uid);
    void setGid(QString gid);
    void setRegistratorName(QString registratorName);
    void setFullName(QString fullName);
    void setHomeDir(QString homeDir);
    void setLoginEngine(QString loginEngine);

    Q_INVOKABLE QList<LocalUser*> getLocalUsers();
    QStringList getUnparsedLocalUsers();
    QList<LocalUser*> ParseLocalUsers(QStringList &usersList);

    //template <typename T>
    //QList<QVariant> ToQVariantList(const QList<T*> &list);

signals:
    void uidChanged(QString uid);
    void gidChanged(QString gid);
    void registratorNameChanged(QString registratorName);
    void fullNameChanged(QString fullName);
    void homeDirChanged(QString homeDir);
    void loginEngineChanged(QString loginEngine);

private:
    QString _UID;
    QString _GID;
    QString _RegistratorName;
    QString _FullName;
    QString _HomeDir;
    QString _LoginEngine;
};

#endif // LOCALUSER_H
