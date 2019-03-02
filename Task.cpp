//
// Created by Dario on 27/02/2019.
//

#include "Task.h"

Task::Task(std::string) {

}

std::string Task::getName() {
    return Task::name;
}

void Task::setName(const std::string name) {
    Task::name = name;
}
