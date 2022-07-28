#include "simplecolumn.h"
SimpleColumn::SimpleColumn(QString name) : AbstractColumn(name)
{

}
QVariant SimpleColumn::colData(const QVariantMap &rowData, int role)
{
    if(role != Qt::DisplayRole)
        return QVariant();

    return rowData.value(name());
}
