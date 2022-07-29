#ifndef LOCALUSERTABLEMODEL_H
#define LOCALUSERTABLEMODEL_H

#include <QObject>
#include <QAbstractListModel>

class LocalUserTableModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        ColorRole = Qt::UserRole + 1,
        TextRole
    };

    LocalUserTableModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void add();
private:
    QStringList m_data;
};

#endif // LOCALUSERTABLEMODEL_H
