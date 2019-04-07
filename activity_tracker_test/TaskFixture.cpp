//
// Created by Dario on 05/04/2019.
//
//
// Created by Dario on 05/04/2019.
//

#include "gtest/gtest.h"

#include "../Task.h"
#include "../Project.h"


class TaskSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        p.setName("New Project");
        p.addTask(&t);
    }
    Project p;
    Task t;
};

TEST_F(TaskSuite, DefaultConstructor) {
    ASSERT_EQ("",t.getName());
    //May fail because of latency between creation of object and test
    ASSERT_LT(t.getTaskStart().msecsTo(QDateTime::currentDateTime()),10);
    ASSERT_LT(t.getTaskEnd().msecsTo(QDateTime::currentDateTime()),10);
}

TEST_F(TaskSuite,SetName){
    t.setName("New name");
    ASSERT_EQ("New name",t.getName());
}

TEST_F(TaskSuite,SetStart){
    QDateTime start;
    start = QDateTime::fromString("01/04/2019 01:00:00","dd/MM/yyyy hh:mm:ss");
    t.setStart(start);
    ASSERT_EQ(start,t.getTaskStart());
}

TEST_F(TaskSuite,SetEnd){
    QDateTime end;
    end = QDateTime::fromString("01/04/2019 02:30:00","dd/MM/yyyy hh:mm:ss");
    t.setEnd(end);
    ASSERT_EQ(end,t.getTaskEnd());
}

TEST_F(TaskSuite,DeleteTask){
    p.deleteTask(1);
    ASSERT_EQ(p.tasks.begin(),p.tasks.end());
}

TEST_F(TaskSuite,Duration){
    QDateTime start;
    QDateTime end;
    start = QDateTime::fromString("01/04/2019 01:00:00","dd/MM/yyyy hh:mm:ss");
    end = QDateTime::fromString("01/04/2019 01:01:00","dd/MM/yyyy hh:mm:ss");
    t.setStart(start);
    t.setEnd(end);
    ASSERT_EQ(t.getDuration(),60);
}


