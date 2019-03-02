//
// Created by Dario on 02/03/2019.
//

#ifndef ACTIVITY_TRACKER_PROJECT_H
#define ACTIVITY_TRACKER_PROJECT_H

#include <string>

class Project {
public:
    Project(std::string name);
    std::string getName();
    void setName(const std::string name);
protected:
    std::string name;
};


#endif //ACTIVITY_TRACKER_PROJECT_H
