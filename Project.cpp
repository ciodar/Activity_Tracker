//
// Created by Dario on 02/03/2019.
//

#include "Project.h"

Project::Project(std::string name) {
    Project::name = name;
}

std::string Project::getName() {
    return Project::name
}

void Project::setName(const std::string name) {
    Project::name = name;
}
