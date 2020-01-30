//
// Created by student on 18.11.2019.
//
#pragma once
#include "Observer.h"
#include <set>
class Observable
{
private:
    std::set<Observer*> observers;
protected:
    void notifyObservers(float);
public:
    void registerObserver(Observer*);
    void unregisterObserver(Observer*);
};
