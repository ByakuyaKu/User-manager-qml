#ifndef SIMPLECOLUMN_H
#define SIMPLECOLUMN_H

#include <QObject>
#include <model/abstractcolumn.h>
#include <QVariant>
class SimpleColumn : public AbstractColumn
{

public:
    SimpleColumn(QString name);

    //AbstractColumn interface
public:
    virtual QVariant colData(const QVariantMap &rowData, int role) override;
};

#endif // SIMPLECOLUMN_H
