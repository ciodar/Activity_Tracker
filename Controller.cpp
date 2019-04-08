//
// Created by Dario on 03/03/2019.
//

#include "Controller.h"

void Controller::createProject(const std::string &name){
    if(model->findProject(name) == model->projects.end())
        model->addProject(name);
}
void Controller::updateProject(const std::string &oldName, const std::string &newName) {
    if(!newName.empty()){
        auto it = model->findProject(oldName);
        if (it != model->projects.end()){
            model->updateProjectName(*it,newName);
        }
    }
}

void Controller::removeProject(const std::string &projectName){
    if(!projectName.empty()){
        auto it = model->findProject(projectName);
        if (it != model->projects.end()){
            model->removeProject(*it);
        }
    }
}

void Controller::addTaskToProject(const std::string &projectName,const std::string &taskName,const QDateTime &startDate,const QDateTime &endDate) {
    //std::cout << "start Date: " << startDate.toString("dd hh:mm:ss").toUtf8().constData() << "end Date: " << endDate.toString("dd hh:mm:ss").toUtf8().constData() << std::endl;
    if(!projectName.empty()){
        auto it = model->findProject(projectName);
        if (it != model->projects.end()){
            model->addTaskToProject((*it),new Task(taskName,startDate,endDate));
        }
    }
}

void Controller::removeTaskFromProject(const std::string &projectName, int taskId) {
    std::list<Task*>::iterator t_it;
    std::list<Project*>::iterator p_it;
    if(!projectName.empty()){
        auto it = model->findProject(projectName);
        if (it != model->projects.end()){
            model->removeTaskFromProject((*it),taskId);
        }
    }
}



Task* Controller::retrieveTaskInfo(const std::string &projectName, int taskId) {
    Task *task;
    if(!projectName.empty()){
        auto it = model->findProject(projectName);
        if (it != model->projects.end()){
            task = (*it)->getTask(taskId);
        }
    }
    return task;
}

QTime Controller::secondsToTime(qint64 seconds)
{
    //TODO: considerare il caso in cui l'effort sia più lungo di 24 ore
    const qint64 DAY = 86400;
    //qint64 days = seconds / DAY;
    QTime t = QTime(0,0).addSecs(seconds % DAY);
    return t;
}

void Controller::updateTask(const std::string &projectName, int taskId,const std::string &newName,const std::string &newProjectName,
                            const QDateTime &newStart,const QDateTime &newEnd) {
    Task* task;
    if(!projectName.empty()){
        auto p_it = model->findProject(projectName);
        if (p_it != model->projects.end()) {
            auto it = (*p_it)->tasks.find(taskId);
            task = it->second;
            if(task == nullptr)
                return;
            task->setName(newName);
            task->setStart(newStart);
            task->setEnd(newEnd);
            if(projectName != newProjectName){
                auto np_it = model->findProject(newProjectName);
                if (np_it != model->projects.end()) {
                    (*np_it)->addTask(new Task(*task));
                    (*p_it)->deleteTask(taskId);
                }
            }
        }
    }
    model->notify();
}