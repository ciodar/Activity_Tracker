//
// Created by Dario on 27/02/2019.
//

#include "Task.h"
Task::Task(){
    Task::name = "";
    Task::taskStart = QDateTime::currentDateTime();
    Task::taskEnd = QDateTime::currentDateTime();
}
Task::Task(std::string name,QDateTime start,QDateTime end) {
    Task::name = name;
    Task::taskStart = start;
    Task::taskEnd = end;
}
Task::Task(const Task& t){
    std::cout <<"Copy constructor called "<< std::endl;
    Task::name = t.name;
    Task::taskStart = t.taskStart;
    Task::taskEnd = t.taskEnd;
}
Task::~Task(){

}

std::string Task::getName() {
    return Task::name;
}

void Task::setName(const std::string name) {
    Task::name = name;
}

void Task::setStart(QDateTime start) {
    Task::taskStart = start;
}

void Task::setEnd(QDateTime end) {
    Task::taskEnd = end;
}

void Task::subscribe(Observer* o) {
    observers.push_back(o);
}

void Task::unsubscribe(Observer* o) {
    observers.remove(o);
}

void Task::notify() {
    for( auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update();
    }
}

QDateTime Task::getTaskStart() {
    return Task::taskStart;
}

QDateTime Task::getTaskEnd() {
    return Task::taskEnd;
}

qint64 Task::getDuration() {
    qint64 duration;
    duration = taskStart.secsTo(taskEnd);
    if(duration < 0)
        return 0;
    else
        return duration;
}
