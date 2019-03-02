//
// Created by Dario on 02/03/2019.
//

#ifndef ACTIVITY_TRACKER_SUBJECT_H
#define ACTIVITY_TRACKER_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void notify() = 0;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
};


#endif //ACTIVITY_TRACKER_SUBJECT_H
