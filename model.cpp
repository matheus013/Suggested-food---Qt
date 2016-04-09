#include "model.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>
#include <QSqlRecord>
#include <QBitArray>

Model::Model() {
    load();
    srand(time(NULL));
}

QVector<Food *> Model::model() {
    return m_model;
}

QVector<Food *> Model::makeGene(int size) {
    QVector<Food *> gene;
    while(gene.size() != size)
        gene << m_model.at(rand() % m_model.size());
    return gene;
}

QBitArray Model::randModel(int lengthModel) {
    QBitArray bit(lengthModel);
    for (int i = 0; i < lengthModel; ++i)
        bit[i] = bool(rand() % 2);
    return bit;
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
            Food * current = new Food(id ,name ,randModel(8), cal, 0);
            m_model.append(current);
        }
    }
}
