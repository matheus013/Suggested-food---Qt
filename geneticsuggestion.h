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
    QVector<QVector<Food*>> m_population;
    QVector<int> weight;
    QBitArray user;
    MathUtil util;
    Model model;
    int m_populationSize;
    int m_calories;
    int m_mealPerDay;

public:
    GeneticSuggestion(int mealPerDay, int calories);
    GeneticSuggestion();
    void run();
    void print();

private:
    void cross();
    void buildPopulation();
    void mutation();
    int adaptation(QVector<Food *> gene);
    int score(Food *reference);
    int harmony(QBitArray reference, int i = 0);
    bool rating();
};

