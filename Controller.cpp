//
// Created by Dario on 03/03/2019.
//

#include "Controller.h"

void Controller::createProject(std::string name){
        model->projects.push_back(new Project(name));
        model->setProjectError("OK, project correctly added!");
}

void Controller::addTaskToProject(std::string projectName, std::string taskName, QDateTime startDate, QDateTime endDate) {
    std::cout << secondsToString(startDate.secsTo(endDate)).toUtf8().constData() << std::endl;
    if(projectName != ""){
        auto it = std::find_if(model->projects.begin(), model->projects.end(),[&projectName](Project* object){return object->getName() == projectName;});
        if (it != model->projects.end())
            (*it)->addTask(new Task(taskName,startDate.date(),QDateTime::fromString(secondsToString(startDate.secsTo(endDate)),"d h:m:s")));
    }
}

/// seconds as "X days, X hours, X minutes, X seconds" string
QString Controller::secondsToString(qint64 seconds)
{
    //TODO: considerare il caso in cui l'effort sia più lungo di un mese
    const qint64 DAY = 86400;
    qint64 days = seconds / DAY;
    QTime t = QTime(0,0).addSecs(seconds % DAY);
    return QString("d%1 %2:%3:%4")
            .arg(days).arg(t.hour()).arg(t.minute()).arg(t.second());
}