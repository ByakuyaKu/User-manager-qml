#include "localusertablemodel.h"
#include "QQmlListProperty"
LocalUserTableModel::LocalUserTableModel(QObject *parent)
{
    m_data.append("old");
       m_data.append("anotherold");
}

int LocalUserTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
           return 0;
       }

       return m_data.size();
}

QVariant LocalUserTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
            return QVariant();
        }

        switch (role) {
        case ColorRole:
            //return QQmlListProperty<QString>(static_cast<QObject *>(this), static_cast<void *>(&m_data));
        case TextRole:
            return m_data.at(index.row());
        default:
            return QVariant();
        }
}

QHash<int, QByteArray> LocalUserTableModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
        roles[ColorRole] = "color";
        roles[TextRole] = "text";

        return roles;
}

void LocalUserTableModel::add()
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
        m_data.append("new");
        endInsertRows();

        m_data[0] = QString("Size: %1").arg(m_data.size());
        QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
        emit dataChanged(index, index);
}
