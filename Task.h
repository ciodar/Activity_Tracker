//
// Created by Dario on 27/02/2019.
//

#ifndef ACTIVITY_TRACKER_TASK_H
#define ACTIVITY_TRACKER_TASK_H

#include <string>
#include <ctime>
#include <list>

#include "Subject.h"


class Task : public Subject {
public:
    explicit Task(std::string name);

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    std::string getName();
    void setName(const std::string name);
    time_t getTaskDate();
    time_t getTaskDuration();
protected:
    std::string name;
    time_t taskDate;
    time_t taskDuration;
private:
    std::list<Observer*> observers;
};


#endif //ACTIVITY_TRACKER_TASK_H
