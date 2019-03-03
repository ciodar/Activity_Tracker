//
// Created by Dario on 02/03/2019.
//

#ifndef ACTIVITY_TRACKER_PROJECT_H
#define ACTIVITY_TRACKER_PROJECT_H

#include <string>
#include <list>

#include "Subject.h"

class Project : public Subject {
public:
    explicit Project(std::string name);

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

    std::string getName();
    void setName(const std::string name);
protected:
    std::string name;
private:
    std::list<Observer*> observers;
};


#endif //ACTIVITY_TRACKER_PROJECT_H
