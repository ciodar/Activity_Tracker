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
    t.setStart(QDateTime::fromString("M1d1y9800:01:02","'M'M'd'd'y'yyhh:mm:ss"));
    ASSERT_EQ(QDateTime::fromString("M1d1y9800:01:02","'M'M'd'd'y'yyhh:mm:ss"),t.getTaskStart());
}

TEST_F(TaskSuite,SetEnd){
    t.setEnd(QDateTime::fromString("M1d1y9800:01:02","'M'M'd'd'y'yyhh:mm:ss"));
    ASSERT_EQ(QDateTime::fromString("M1d1y9800:01:02","'M'M'd'd'y'yyhh:mm:ss"),t.getTaskEnd());
}

TEST_F(TaskSuite,DeleteTask){
    p.deleteTask(1);
    ASSERT_EQ(p.tasks.begin(),p.tasks.end());
}
