#include <QCoreApplication>
#include "geneticsuggestion.h"
#include <QDebug>
#include <mathutil.h>
#include <QVector>
#include <QTime>
int main(int argc, char *argv[]) {
        GeneticSuggestion genetic(42,2949);
        genetic.run();
        genetic.print();
}
