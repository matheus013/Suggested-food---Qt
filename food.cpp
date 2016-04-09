#include "food.h"

QBitArray Food::info() const {
    return m_info;
}

void Food::setInfo(const QBitArray &info) {
    m_info = info;
}

int Food::calories() const {
    return m_calories;
}

void Food::setCalories(int calories) {
    m_calories = calories;
}

int Food::getId() const {
    return id;
}

void Food::setId(int value) {
    id = value;
}

int Food::getTime() const {
    return m_time;
}

void Food::setTime(int time) {
    m_time = time;
}

QString Food::getName() const
{
    return m_name;
}

void Food::setName(const QString &name)
{
    m_name = name;
}

Food::Food(int id, QString name, QBitArray info, int calories, int time) {
    setId(id);
    setCalories(calories);
    setInfo(info);
    setTime(time);
    setName(name);
}
