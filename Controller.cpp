//
// Created by Dario on 03/03/2019.
//

#include "Controller.h"

void Controller::createProject(const std::string name){
    if(model->findProject(name) == model->projects.end())
        model->projects.push_back(new Project(name));
    model->notify();
}
void Controller::updateProject(const std::string oldName, const std::string newName) {
    if(!newName.empty()){
        std::list<Project*>::iterator it = model->findProject(oldName);
        if (it != model->projects.end()){
            (*it)->setName(newName);
        }
    }
    model->notify();
}
void Controller::removeProject(const std::string name){
    if(name != ""){
        std::list<Project*>::iterator it = model->findProject(name);
        if (it != model->projects.end()){
            model->projects.remove(*it);
        }
    }
    model->notify();
}

void Controller::addTaskToProject(std::string projectName, std::string taskName, QDateTime startDate, QDateTime endDate) {
    //std::cout << "start Date: " << startDate.toString("dd hh:mm:ss").toUtf8().constData() << "end Date: " << endDate.toString("dd hh:mm:ss").toUtf8().constData() << std::endl;
    if(projectName != ""){
        std::list<Project*>::iterator it = model->findProject(projectName);
        if (it != model->projects.end()){
            (*it)->addTask(new Task(taskName,startDate,endDate));
/*            for(t_it = (*it)->tasks.begin(); t_it != (*it)->tasks.end(); ++t_it){
//                std::cout << "Task duration: " << (*t_it)->getTaskDuration().toString("dd hh:mm:ss").toUtf8().constData();
//                std::cout << "Real string" << QDateTime::fromString(secondsToTime(startDate.secsTo(endDate)),"dd hh:mm:ss").toString("dd hh:mm:ss").toUtf8().constData();
            }*/
        }
    }
    model->notify();
}

void Controller::removeTaskFromProject(std::string projectName, int taskId) {
    std::list<Task*>::iterator t_it;
    std::list<Project*>::iterator p_it;
    //std::cout << "Controller removing line" << taskId << "of project " << projectName << std::endl;
    if(projectName != ""){
        std::list<Project*>::iterator it = model->findProject(projectName);
        if (it != model->projects.end()){
            (*it)->deleteTask(taskId);
          /*  t_it = std::find_if((*p_it)->tasks.begin(), (*p_it)->tasks.end(), [&taskName](Task* task){return task->getName() == taskName;});
            if(t_it != (*p_it)->tasks.end())
                (*p_it)->tasks.remove((*t_it));*/
        }
    }
    model->notify();
}



Task* Controller::retrieveTaskInfo(std::string projectName, int taskId) {
    Task *task;
    if(projectName != ""){
        std::list<Project*>::iterator it = model->findProject(projectName);
        if (it != model->projects.end()){
            task = (*it)->getTask(taskId);
            /*  t_it = std::find_if((*p_it)->tasks.begin(), (*p_it)->tasks.end(), [&taskName](Task* task){return task->getName() == taskName;});
              if(t_it != (*p_it)->tasks.end())
                  (*p_it)->tasks.remove((*t_it));*/
        }
    }
    return task;
}

QTime Controller::secondsToTime(qint64 seconds)
{
    //TODO: considerare il caso in cui l'effort sia più lungo di 24 ore
    const qint64 DAY = 86400;
    qint64 days = seconds / DAY;
    QTime t = QTime(0,0).addSecs(seconds % DAY);
    return t;
}

void Controller::updateTask(std::string projectName, int taskId, std::string newName, std::string newProjectName,
                            QDateTime newStart, QDateTime newEnd) {
    Task* task;
    if(projectName != ""){
        std::list<Project*>::iterator p_it = model->findProject(projectName);
        if (p_it != model->projects.end()) {
            auto it = (*p_it)->tasks.find(taskId);
            task = it->second;
            if(task == 0)
                return;
            task->setName(newName);
            task->setStart(newStart);
            task->setEnd(newEnd);
            if(projectName != newProjectName){
                std::list<Project*>::iterator np_it = model->findProject(newProjectName);
                if (np_it != model->projects.end()) {
                    (*np_it)->addTask(new Task(*task));
                    (*p_it)->deleteTask(taskId);
                }
            }
        }
    }
    model->notify();
}