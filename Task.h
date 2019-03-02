//
// Created by Dario on 27/02/2019.
//

#ifndef ACTIVITY_TRACKER_TASK_H
#define ACTIVITY_TRACKER_TASK_H

#include <string>
#include <ctime>

#include "Project.h"

class Task {
public:
    Task(std::string name);
    std::string getName();
    void setName(const std::string name);
protected:
    std::string name;
    time_t taskDate;
    Project* taskProject;
};


#endif //ACTIVITY_TRACKER_TASK_H
