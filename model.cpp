#include "model.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>
#include <QSqlRecord>
#include <QBitArray>

QVector<Food *> Model::model() {
    //    load();
    for (int i = 0; i < 10000; ++i)
        m_model.append(new Food(i,randModel(8), rand() % 1100));
    return m_model;
}

QBitArray Model::randModel(int lengthModel) {
    QBitArray bit(lengthModel);
    for (int i = 0; i < lengthModel; ++i)
        bit[i] = bool(rand() % 2);
    return bit;
}

Model::Model() {
    srand(time(NULL));
}

void Model::load() {
//    QSqlQuery query;
//    QString tag = "SELECT * FROM nutron_recommended_food";
//    query.prepare(tag);
//    if(!query.exec())
//        qDebug() << query.lastError();
//    else{
//        QBitArray array(query.record().count());
//        while(query.next()) {
//            for (int i = 0; i < query.record().count(); ++i)
//                array[i] = query.value(i).toBool();
//            m_model.append(array);
//        }
//    }
}
