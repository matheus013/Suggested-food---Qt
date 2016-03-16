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

int Food::getId() const
{
    return id;
}

void Food::setId(int value)
{
    id = value;
}

Food::Food(int id, QBitArray info, int calories) {
    setCalories(calories);
    setInfo(info);
    setId(id);
}
