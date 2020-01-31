#include "displacement.h"
#include <QDebug>

Displacement::Displacement(QObject *parent) : QObject(parent)
{
    value = 1;
}

void Displacement::set(double v)
{
    value = v;
    qDebug() << v;
    emit changed(get());
}

double Displacement::get()
{
    return value;
}
