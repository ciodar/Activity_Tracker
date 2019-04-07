//
// Created by Dario on 07/04/2019.
//
#include "gtest/gtest.h"
#include "../Model.h"
#include "../Controller.h"
class MVCSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        model = new Model;
        controller = new Controller(model);
    }
    Model* model;
    Controller*controller;
};

TEST_F(MVCSuite,DefaultConstructor){
    ASSERT_EQ(model->projects.rbegin(),model->projects.rend());
}

TEST_F(MVCSuite,ProjectCreation){
    controller->createProject("New Project");
    ASSERT_NE(model->findProject("New Project"),model->projects.end());
}

TEST_F(MVCSuite,ProjectChange){
    controller->createProject("New Project");
    controller->updateProject("New Project","Changed Name");
    ASSERT_EQ(model->findProject("New Project"),model->projects.end());
    ASSERT_NE(model->findProject("Changed Name"),model->projects.end());
}

TEST_F(MVCSuite,ProjectRemove){
    controller->createProject("New Project");
    controller->removeProject("New Project");
    ASSERT_EQ(model->projects.rbegin(),model->projects.rend());
}

TEST_F(MVCSuite,TaskAdd){
    controller->createProject("Project");
    controller->addTaskToProject("Project","New Task",QDateTime::currentDateTime(),QDateTime::currentDateTime());
    auto it = model->findProject("Project");
    ASSERT_NE((*it)->tasks.size(),0);
    ASSERT_EQ(controller->retrieveTaskInfo("Project",1)->getName(),"New Task");
}

TEST_F(MVCSuite,TaskUpdate){
    Task* task;
    QDateTime start;
    QDateTime end;
    start = QDateTime::fromString("01/04/2019 01:00:00","dd/MM/yyyy hh:mm:ss");
    end = QDateTime::fromString("01/04/2019 02:30:00","dd/MM/yyyy hh:mm:ss");
    controller->createProject("Project");
    controller->addTaskToProject("Project","New Task",QDateTime::currentDateTime(),QDateTime::currentDateTime());
    controller->updateTask("Project",1,"Updated Name","Project",start,end);
    task = controller->retrieveTaskInfo("Project",1);
    ASSERT_EQ("Updated Name",task->getName());
    ASSERT_EQ(start,task->getTaskStart());
    ASSERT_EQ(end,task->getTaskEnd());
    //task = controller->retrieveTaskInfo("Project",1);
    //ASSERT_EQ(task,0);
}

TEST_F(MVCSuite,TaskRemove){
    controller->createProject("Project");
    controller->addTaskToProject("Project","New Task",QDateTime::currentDateTime(),QDateTime::currentDateTime());
    controller->removeTaskFromProject("Project",1);
    ASSERT_EQ((*model->findProject("Project"))->tasks.size(),0);
    //task = controller->retrieveTaskInfo("Project",1);
    //ASSERT_EQ(task,0);
}