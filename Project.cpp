//
// Created by Dario on 02/03/2019.
//

#include "Project.h"

Project::Project(std::string name) {
    Project::name = name;
}

std::string Project::getName() {
    return Project::name;
}

void Project::setName(const std::string name) {
    Project::name = name;
}

void Project::subscribe(Observer* o) {
    observers.push_back(o);
}

void Project::unsubscribe(Observer* o) {
    observers.remove(o);
}

void Project::notify() {
    for( auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update();
    }
}

void Project::deleteTask(Task *task) {
    tasks.remove(task);
    delete task;
    notify();
}

void Project::addTask(Task *task) {
    tasks.push_back(task);
    notify();
}
