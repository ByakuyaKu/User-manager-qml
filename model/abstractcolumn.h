#ifndef ABSTRACTCOLUMN_H
#define ABSTRACTCOLUMN_H

#include <QObject>

class AbstractColumn
{

public:
    AbstractColumn(QString name);
    QString name() {return _name;}

    virtual QVariant colData(const QVariantMap &rowData, int role = Qt::DisplayRole) = 0;

private:
    QString _name;
};

#endif // ABSTRACTCOLUMN_H
