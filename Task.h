//
// Created by Dario on 27/02/2019.
//

#ifndef ACTIVITY_TRACKER_TASK_H
#define ACTIVITY_TRACKER_TASK_H

#include <string>
#include <ctime>
#include <list>

#include "Project.h"
#include "Subject.h"


class Task : public Subject {
public:
    explicit Task(std::string name);

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

    std::string getName();
    void setName(const std::string name);

protected:
    std::string name;
    time_t taskDate;
    Project* taskProject;
private:
    std::list<Observer*> observers;
};


#endif //ACTIVITY_TRACKER_TASK_H
