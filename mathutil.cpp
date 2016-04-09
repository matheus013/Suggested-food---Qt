#include "mathutil.h"
#include <QVector>
#include <QtMath>
#include <QBitArray>
#include <QDebug>

MathUtil::MathUtil() {}

double MathUtil::standardDeviation(QVector<double> vector) {
    int deviation = 0, mid = average(vector);
    foreach (int aux, vector)
        deviation += qPow(aux - mid,2);
    return (double) qSqrt(deviation / (vector.size() - 1));
}

double MathUtil::average(QVector<double> vector) {
    return sum(vector) / vector.size();
}

double MathUtil::sum(QVector<double> vector) {
    double sum = 0;
    foreach (int aux, vector)
        sum += aux;
    return sum;
}

double MathUtil::sum(QVector<Food *> vector){
    double sum = 0;
    foreach (Food* aux, vector)
        sum += aux->calories();
    return sum;
}

bool MathUtil::approach(double number,double total , double margin) {
    return (number < total * double(1 + margin) && (number > total * double(1 - margin)));
}

QBitArray MathUtil::join(QBitArray a, QBitArray b) {
    int start = a.size();
    a.resize(start + b.size());
    for (int i = start; i < a.size(); ++i)
        a.setBit(i,b.at(i - start));
    return a;
}
