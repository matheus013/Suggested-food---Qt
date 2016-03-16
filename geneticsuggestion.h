#pragma once

#include <QObject>
#include <QVector>
#include <QBitArray>
#include "model.h"
#include "food.h"

class GeneticSuggestion : public QObject {
    Q_OBJECT
    int m_populationSize;
    int m_calories;
    QVector<Food*> m_base;
    QVector<Food*> m_population;
    Model model;
    QBitArray user;

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
    QBitArray join(QBitArray a,QBitArray b);
    int adaptation();
};

