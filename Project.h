//
// Created by Dario on 02/03/2019.
//

#ifndef ACTIVITY_TRACKER_PROJECT_H
#define ACTIVITY_TRACKER_PROJECT_H

#include <string>
#include <list>

#include "Subject.h"
#include "Task.h"

class Project : public Subject {
public:
    explicit Project(std::string name);
    bool operator==(const std::string rhs) const;
    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    std::string getName() const;
    void setName(const std::string name);
    void deleteTask(Task *task);
    void addTask(Task *task);
protected:
    std::string name;
private:
    std::list<Observer*> observers;
    std::list<Task*> tasks;
};


#endif //ACTIVITY_TRACKER_PROJECT_H
