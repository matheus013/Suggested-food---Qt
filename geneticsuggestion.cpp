#include "geneticsuggestion.h"
#include "model.h"
#include <QDebug>
#include <iostream>
#include <stdio.h>
using namespace std;
GeneticSuggestion::GeneticSuggestion(int mealPerDay, int calories) {
    m_base = model.model();
    m_populationSize = mealPerDay*7;
    m_mealPerDay = mealPerDay;
    m_calories = calories;
    user = model.randModel(8);
}

GeneticSuggestion::GeneticSuggestion() {}

void GeneticSuggestion::run() {
    buildPopulation();
    do {
        cross();
        mutation();
    } while (rating());
}

void GeneticSuggestion::cross() {
    int length = m_population.size();
    for (int i = 0; i < length; ++i)
        swap(m_population[rand() % length], m_population[rand() % length]);
}

int GeneticSuggestion::harmony(QBitArray reference, int i) {
    if(i == reference.size()/ 2 - 1)
        return (reference[i] == reference[reference.size() - 1 - i]);
    return (reference[i] == reference[reference.size() - 1 - i]) +  harmony(reference, ++i);
}

bool GeneticSuggestion::rating() {
    QVector<double> scores;
    foreach (QVector<Food *> gene, m_population) {
        scores << adaptation(gene);
    }
    double rate = util.standardDeviation(scores);
    return rate < -50 || rate > 50;
}

int GeneticSuggestion::adaptation(QVector<Food *> gene) {
    int adaptationScore = 0;
    foreach (Food * current, gene)
        adaptationScore += score(current);
    return adaptationScore;
}

void GeneticSuggestion::buildPopulation(){
    while(m_population.size() != 7)
        m_population << model.makeGene(m_mealPerDay);
}

int GeneticSuggestion::score(Food* reference) {
    double first = (double) harmony(util.join(user,reference->info()));
    double secund = (double) reference->calories();
    return  ((first/8) * 0.6 - (secund/1100) * 0.4) * 1000;
}

void GeneticSuggestion::print() {
    foreach (QVector<Food*> i, m_population) {
        QString out = "";
        foreach (Food* f, i) {
            out += '[' + f->getName() + " " + QString::number(f->calories()) + ']';
        }
        qDebug() << out;
    }
}

void GeneticSuggestion::mutation() {
    for (int i = 0; i < m_population.size(); ++i) {
        QVector<Food *> gene = model.makeGene(m_mealPerDay);
        if(adaptation(m_population[i]) < adaptation(gene))
            m_population[i] = gene;
    }
}
