#pragma once

#include <QObject>
#include <QVector>
#include <QBitArray>
#include "model.h"
#include "food.h"
#include "mathutil.h"

class GeneticSuggestion : public QObject {
    Q_OBJECT
    QVector<Food*> m_base;
    QVector<Food*> m_population;
    QVector<int> weight;
    QBitArray user;
    MathUtil util;
    Model model;
    int m_populationSize;
    int m_calories;

public:
    GeneticSuggestion(int populationSize, int calories);
    void run();
    void print();

private:
    void cross();
    void buildPopulation();
    int score(Food *reference);
    void mutation();
    int harmony(QBitArray reference, int i = 0);
    bool adaptation();
};

