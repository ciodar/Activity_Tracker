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
    void createProject(const std::string &name);
    void updateProject(const std::string &oldName,const std::string &newName);
    void removeProject(const std::string &projectName);
    void addTaskToProject(const std::string &projectName,const std::string &taskName,const QDateTime &startDate,const QDateTime &endDate);
    void removeTaskFromProject(const std::string &projectName, int taskId);
    void updateTask(const std::string &projectName,int taskId,const std::string &newName,const std::string &newProjectName,const QDateTime &newStart,const QDateTime &newEnd);
    Task* retrieveTaskInfo(const std::string &projectName, int taskId);
    QTime secondsToTime(qint64 seconds);
private:
    Model* model;
};

#endif //ACTIVITY_TRACKER_CONTROLLER_H
