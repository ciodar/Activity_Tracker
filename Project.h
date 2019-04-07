//
// Created by Dario on 02/03/2019.
//

#ifndef ACTIVITY_TRACKER_PROJECT_H
#define ACTIVITY_TRACKER_PROJECT_H

#include <string>
#include <map>

#include "Subject.h"
#include "Task.h"

class Project : public Subject {
public:
    Project();
    explicit Project(std::string name);
    ~Project();
    bool operator==(const std::string rhs) const;
    bool operator==(const Project rhs) const;
    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    std::string getName() const;
    void setName(const std::string name);
    void deleteTask(int taskId);
    void addTask(Task *task);
    Task* getTask(int taskId);
    std::map<int,Task*> tasks;
protected:
    std::string name;
private:
    std::list<Observer*> observers;
};


#endif //ACTIVITY_TRACKER_PROJECT_H
