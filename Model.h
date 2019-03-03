//
// Created by Dario on 03/03/2019.
//

#ifndef ACTIVITY_TRACKER_MODEL_H
#define ACTIVITY_TRACKER_MODEL_H


#include <list>
#include "Subject.h"

class Model : public Subject {
public:
    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;
private:
    std::list<Observer*> observers;
};

#endif //ACTIVITY_TRACKER_MODEL_H
