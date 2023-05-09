//
// Created by sttony on 5/7/23.
//

#ifndef TINYNOTE_NAVTREEITEM_H
#define TINYNOTE_NAVTREEITEM_H
#include <QAbstractItemModel>

class NavTreeItem : public QAbstractItemModel {
Q_OBJECT
public:
    explicit NavTreeItem(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    virtual  QModelIndex parent(const QModelIndex &index) const override;

};


#endif //TINYNOTE_NAVTREEITEM_H
