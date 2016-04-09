#pragma once
#include <QObject>
#include "food.h"

class MathUtil : public QObject {
    Q_OBJECT
    enum{

    };
public:
    MathUtil();
    double standardDeviation(QVector<double> vector);
    double average(QVector<double> vector);
    double sum(QVector<double> vector);
    double sum(QVector<Food*> vector);
    bool approach(double number, double total, double margin);
    QBitArray join(QBitArray a,QBitArray b);
};
