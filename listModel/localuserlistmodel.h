#ifndef LOCALUSERLISTMODEL_H
#define LOCALUSERLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
//#include<model/abstractcolumn.h>
#include <listModel/localuser.h>
#include <QQmlListProperty>

class LocalUserListModel : public QObject
{
    Q_PROPERTY(QQmlListProperty<LocalUser> data READ data NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")
    Q_OBJECT
public:
    //LocalUserListModel();

    LocalUserListModel(QObject *parent = nullptr);

    //void registerColumn(AbstractColumn* column);
    void addRow(QVariantMap rowData);
    //QHash<int, QByteArray> roleNames() const;

    QQmlListProperty<LocalUser> data();
    Q_INVOKABLE void add(LocalUser *user);
    //convenience methods
    int idByRow(int row) const;
    //int colByName(QString name) const;
    //QString nameByCol(int col) const;
signals:
    void dataChanged();
private:
    static void appendData(QQmlListProperty<LocalUser> *list, LocalUser *value);
    static int countData(QQmlListProperty<LocalUser> *list);
    static LocalUser *atData(QQmlListProperty<LocalUser> *list, int index);
    static void clearData(QQmlListProperty<LocalUser> *list);

    QList<LocalUser*> _localUsers;
};

#endif // LOCALUSERLISTMODEL_H
