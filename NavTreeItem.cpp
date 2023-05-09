//
// Created by sttony on 5/7/23.
//

#include "NavTreeItem.h"

NavTreeItem::NavTreeItem(QObject *parent) : QAbstractItemModel(parent) {

}

int NavTreeItem::rowCount(const QModelIndex &parent) const {
    if (!parent.isValid())
        return 3;
    else
        return 2;
}

int NavTreeItem::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant NavTreeItem::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        if (!index.parent().isValid())
            return QString("Parent %1").arg(index.row());
        else
            return QString("Child %1-%2").arg(index.parent().row()).arg(index.row());
    }

    return {};
}

QVariant NavTreeItem::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        return QString("Header");
    return {};
}

QModelIndex NavTreeItem::index(int row, int column, const QModelIndex &parent) const {
    if (!parent.isValid())
        return createIndex(row, column);
    else
        return createIndex(row, column, parent.row() * 2 + row + 1);
}

QModelIndex NavTreeItem::parent(const QModelIndex &index) const {
    if (!index.isValid())
        return QModelIndex();

    int parentRow = (index.internalId() - 1) / 2;

    if (parentRow == -1)
        return QModelIndex();
    else
        return createIndex(parentRow, 0);
}
