//
// Created by Dario on 02/03/2019.
//

#ifndef ACTIVITY_TRACKER_OBSERVER_H
#define ACTIVITY_TRACKER_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {}

    virtual void update() = 0;

    virtual void attach() = 0;
    virtual void detach() = 0;
};


#endif //ACTIVITY_TRACKER_OBSERVER_H
