#include "geneticsuggestion.h"
#include "model.h"
#include <QDebug>
#include <iostream>
#include <stdio.h>
using namespace std;
GeneticSuggestion::GeneticSuggestion(int populationSize,int calories) {
    m_base = model.model();
    m_populationSize = populationSize;
    m_calories = calories;
    user = model.randModel(8);
}

void GeneticSuggestion::run() {
    do {
        buildPopulation();
        cross();
        mutation();
    } while (adaptation());
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

bool GeneticSuggestion::adaptation() {
    int midScore = 0;
    foreach (Food* var, m_population)
        midScore+= score(var);
    double result = util.sum(m_population)/7;
    return !util.approach(result, m_calories,0.05) || midScore/m_populationSize <= 200;
}

void GeneticSuggestion::buildPopulation(){
    m_population.clear();
    for (int i = 0; i < m_populationSize; ++i)
        m_population.append(m_base.at(rand() % m_base.size()));
}

int GeneticSuggestion::score(Food* reference) {
    double first = (double) harmony(util.join(user,reference->info()));
    double secund = (double) reference->calories();
    return  ((first/8) * 0.6 - (secund/1100) * 0.4) * 1000;
}

void GeneticSuggestion::print() {
    for (int i = 0; i < m_population.size(); ++i) {
        printf("[%5d - %3d] ", m_population[i]->calories(),score(m_population[i]));
        if((i + 1)% 6 == 0) cout << endl;
    }
}

void GeneticSuggestion::mutation() {
    for (int i = 0; i < m_population.size(); ++i) {
        int j = rand() % m_base.size();
        if(score(m_population[i]) < score(m_base[j]))
            m_population[i] = m_base[j];
    }
}
