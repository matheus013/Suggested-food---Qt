#pragma once

#include <QObject>
#include "./bd/daobject.h"
#include <QVector>
#include <QBitArray>
#include "food.h"

class Model : public QObject {
    Q_OBJECT
    DAObject dao;
    QVector<Food *> m_model;
public:
    Model();
    QVector<Food *> model();
    QBitArray randModel(int lengthModel);
private:
    void load();
};

