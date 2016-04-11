#ifndef MEAL_H
#define MEAL_H

#include <QObject>

class Meal : public QObject
{
    Q_OBJECT
public:
    explicit Meal(QObject *parent = 0);

signals:

public slots:
};

#endif // MEAL_H