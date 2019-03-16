//
// Created by Dario on 03/03/2019.
//

#include "Controller.h"

void Controller::createProject(std::string name){
        model->projects.push_back(new Project(name));
        model->setProjectError("OK, project correctly added!");
}