#pragma once

#include <QObject>
#include <QBitArray>

class Food : public QObject {
    Q_OBJECT
    QBitArray m_info;
    int m_calories;
    int id;
public:
    Food(int id, QBitArray info, int calories);

    QBitArray info() const;
    void setInfo(const QBitArray &info);
    int calories() const;
    void setCalories(int calories);
    int getId() const;
    void setId(int value);
};
