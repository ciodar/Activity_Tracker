//
// Created by Dario on 02/03/2019.
//

#include "Project.h"

Project::Project() {
    Project::name = "";
}

Project::Project(std::string name) {
    Project::name = name;
}

Project::~Project(){
    for(auto it = Project::tasks.begin(); it != Project::tasks.begin(); ++it){
        delete it->second;
    }
}
std::string Project::getName() const {
    return Project::name;
}

void Project::setName(std::string name) {
    Project::name = name;
}

void Project::deleteTask(int taskId) {
    auto it = tasks.find(taskId);
    delete it->second;
    tasks.erase(taskId);
    //TODO: project does not directly notify view.Is it possible to do?
    //notify();
}

void Project::addTask(Task *task) {
    int key;
    if(tasks.rbegin() != tasks.rend())
        key = tasks.rbegin()->first + 1;
    else
        key = 1;
    tasks.insert(std::make_pair(key,task));
}

Task* Project::getTask(int taskId) {
    return tasks[taskId];
}

bool Project::operator==(const std::string &rhs) const {
    return Project::name == rhs;
}

bool Project::operator==(const Project &rhs) const {
    return Project::name == rhs.getName();
}

