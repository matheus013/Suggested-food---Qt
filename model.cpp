#include "model.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>
#include <QSqlRecord>
#include <QBitArray>

QVector<Food *> Model::model() {
        load();
//    for (int i = 0; i < 10000; ++i)
//        m_model.append(new Food(i,"",randModel(8), rand() % 1100 + 1, 0));
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
    QSqlQuery query;
    QString tag = "SELECT * FROM nutron_food";
    query.prepare(tag);
    if(!query.exec())
        qDebug() << query.lastError();
    else{
        while(query.next()) {
            int id = query.value("food_id").toInt();
            QString name = query.value("name").toString();
            int cal = query.value("calorificvalue").toInt();
            Food * current = new Food(id ,name ,randModel(8), cal);
            m_model.append(current);
        }
    }
}
