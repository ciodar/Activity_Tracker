//
// Created by Dario on 03/03/2019.
//

#ifndef ACTIVITY_TRACKER_CONTROLLER_H
#define ACTIVITY_TRACKER_CONTROLLER_H

#include "Model.h"
#include "Project.h"
#include <list>
#include <algorithm>
#include <QDateTime>

class Controller {
public:
    explicit Controller(Model* m) : model(m) {}
    void createProject(std::string name);
    void addTaskToProject(std::string projectName, std::string taskName,QDateTime startDate,QDateTime endDate);
    QString secondsToString(qint64 seconds);
private:
    Model* model;
};

#endif //ACTIVITY_TRACKER_CONTROLLER_H
