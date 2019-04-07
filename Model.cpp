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

std::list<Project *>::iterator Model::findProject(std::string projectName) {
    //Can be replaced with auto
    std::list<Project*>::iterator it = std::find_if(Model::projects.begin(), Model::projects.end(),[&projectName](Project* object){return object->getName() == projectName;});
    return it;
}


