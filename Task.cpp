//
// Created by Dario on 27/02/2019.
//

#include "Task.h"

Task::Task(std::string name,QDate start,QDateTime duration) {
    Task::name = name;
    Task::taskDate = start;
    Task::taskDuration = duration;
}

std::string Task::getName() {
    return Task::name;
}

void Task::setName(const std::string name) {
    Task::name = name;
}

void Task::subscribe(Observer* o) {
    observers.push_back(o);
}

void Task::unsubscribe(Observer* o) {
    observers.remove(o);
}

void Task::notify() {
    for( auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update();
    }
}

QDate Task::getTaskDate() {
    return Task::taskDate;
}

QDateTime Task::getTaskDuration() {
    return Task::taskDuration;
}
