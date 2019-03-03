//
// Created by Dario on 03/03/2019.
//

#include "Model.h"

void Model::notify() {
    for (Observer* observer : observers)
        observer->update();
}

void Model::setData(const int i) {
    data = i;
    notify();
}

void Model::addObserver(Observer* o) {
    observers.push_back(o);
}

void Model::removeObserver(Observer* o) {
    observers.remove(o);
}
