#include <QCoreApplication>
#include "geneticsuggestion.h"
#include <QDebug>
#include <mathutil.h>
#include <QVector>
#include <QTime>
int main(int argc, char *argv[]) {
        GeneticSuggestion genetic(6,2900);
        genetic.run();
        genetic.print();
}
