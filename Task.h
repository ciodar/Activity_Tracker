//
// Created by Dario on 27/02/2019.
//

#ifndef ACTIVITY_TRACKER_TASK_H
#define ACTIVITY_TRACKER_TASK_H

#include <string>
#include <ctime>
#include <list>
#include <QDateTime>
#include "Subject.h"


class Task : public Subject {
public:
    explicit Task(std::string name,QDate start,QDateTime duration);

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    std::string getName();
    void setName(const std::string name);
    QDate getTaskDate();
    QDateTime getTaskDuration();
protected:
    std::string name;
    QDate taskDate;
    QDateTime taskDuration;
private:
    std::list<Observer*> observers;
};


#endif //ACTIVITY_TRACKER_TASK_H
