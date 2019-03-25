//
// Created by Dario on 03/03/2019.
//

#include "Controller.h"

void Controller::createProject(std::string name){
    //TODO handle duplicates
    model->projects.push_back(new Project(name));
    model->setProjectError("OK, project correctly added!");
    model->notify();
}

void Controller::removeProject(std::string name){
    if(name != ""){
        auto it = std::find_if(model->projects.begin(), model->projects.end(),[&name](Project* object){return object->getName() == name;});
        if (it != model->projects.end()){
            model->projects.erase(it);
        }
    }
    model->notify();
}
void Controller::addTaskToProject(std::string projectName, std::string taskName, QDateTime startDate, QDateTime endDate) {
    std::list<Task*>::iterator t_it;
    std::cout << "start Date: " << startDate.toString("dd hh:mm:ss").toUtf8().constData() << "end Date: " << endDate.toString("dd hh:mm:ss").toUtf8().constData() << std::endl;
    if(projectName != ""){
        auto it = std::find_if(model->projects.begin(), model->projects.end(),[&projectName](Project* object){return object->getName() == projectName;});
        if (it != model->projects.end()){
            (*it)->addTask(new Task(taskName,startDate.date(),secondsToTime(startDate.secsTo(endDate))));
/*            for(t_it = (*it)->tasks.begin(); t_it != (*it)->tasks.end(); ++t_it){
//                std::cout << "Task duration: " << (*t_it)->getTaskDuration().toString("dd hh:mm:ss").toUtf8().constData();
//                std::cout << "Real string" << QDateTime::fromString(secondsToTime(startDate.secsTo(endDate)),"dd hh:mm:ss").toString("dd hh:mm:ss").toUtf8().constData();
            }*/
        }
    }
    model->notify();
}


/// seconds as "X days, X hours, X minutes, X seconds" string
QTime Controller::secondsToTime(qint64 seconds)
{
    //TODO: considerare il caso in cui l'effort sia più lungo di 24 ore
    const qint64 DAY = 86400;
    qint64 days = seconds / DAY;
    QTime t = QTime(0,0).addSecs(seconds % DAY);
    return t;
}