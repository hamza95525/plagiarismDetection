//
// Created by student on 18.11.2019.
//
#include "Obsevable.h"
void Observable::notifyObservers(float value) {
    for(Observer* observer : observers)
        observer->notify(value);
}
void Observable::registerObserver(Observer * Ob) {
    observers.insert(Ob);
}
void Observable::unregisterObserver(Observer * Ob) {
    observers.erase(Ob);
}
