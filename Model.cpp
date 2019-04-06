//
// Created by Dario on 03/03/2019.
//

#include "Model.h"

void Model::notify() {
    for (Observer* observer : observers)
        observer->update();
}

void Model::subscribe(Observer* o) {
    observers.push_back(o);
}

void Model::unsubscribe(Observer* o) {
    observers.remove(o);
}


