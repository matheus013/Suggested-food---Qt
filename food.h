#pragma once

#include <QObject>
#include <QBitArray>

class Food : public QObject {
    Q_OBJECT
    int id;
    QString m_name;
    QBitArray m_info;
    int m_calories;
    int m_time;
public:
    Food(int id,QString name, QBitArray info, int calories,int time);

    QBitArray info() const;
    void setInfo(const QBitArray &info);
    int calories() const;
    void setCalories(int calories);
    int getId() const;
    void setId(int value);
    int getTime() const;
    void setTime(int time);
    QString getName() const;
    void setName(const QString &name);
};
