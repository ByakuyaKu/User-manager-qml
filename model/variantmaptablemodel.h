#ifndef VARIANTMAPTABLEMODEL_H
#define VARIANTMAPTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <model/abstractcolumn.h>
#include <model/simplecolumn.h>

//AbstractColumn class
//class AbstractColumn
//{

//public:
//    AbstractColumn(QString name);
//    QString name() {return _name;}

//    virtual QVariant colData(const QVariantMap &rowData, int role = Qt::DisplayRole) = 0;

//private:
//    QString _name;
//};

//default column implementation
//class SimpleColumn : public AbstractColumn
//{
//public:
//    SimpleColumn(QString name);

//    //AbstractColumn interface
//public:
//    virtual QVariant colData(const QVariantMap &rowData, int role) override;
//};

class VariantMapTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    VariantMapTableModel(QObject *parent = nullptr);

    void registerColumn(AbstractColumn* column);
    void addRow(QVariantMap rowData);
    QHash<int, QByteArray> roleNames() const;

    //convenience methods
    int idByRow(int row) const;
    int colByName(QString name) const;
    QString nameByCol(int col) const;

private:
    //storing data members
    QList<int> _rowIndex;
    QHash<int, QVariantMap> _dataHash;
    QList<AbstractColumn*> _columns;

    //QAbstractItemModel interfaces
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &parent, int role) const override;
};

#endif // VARIANTMAPTABLEMODEL_H
