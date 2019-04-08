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
    auto it = std::find_if(Model::projects.begin(), Model::projects.end(),[&projectName](Project* object){return object->getName() == projectName;});
    return it;
}

void Model::addProject(std::string name) {
    projects.push_back(new Project(name));
    notify();
}

void Model::updateProjectName(Project *project,const std::string &newName) {
    project->setName(newName);
    notify();
}

void Model::removeProject(Project *project) {
    projects.remove(project);
    notify();
}

void Model::addTaskToProject(Project *project, Task *task) {
    project->addTask(task);
    notify();
}

void Model::removeTaskFromProject(Project *project,int taskId){
    project->deleteTask(taskId);
    notify();
}




