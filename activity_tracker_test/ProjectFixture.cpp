//
// Created by Dario on 05/04/2019.
//

#include "gtest/gtest.h"

#include "../Project.h"


class ProjectSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        p.setName("Test Project");
        q.setName("Test Project");
    }

    Project p;
    Project q;
};

TEST_F(ProjectSuite, DefaultConstructor) {
    Project p;
    ASSERT_EQ("",p.getName());
    ASSERT_EQ(p.tasks.begin(),p.tasks.end());
}

TEST_F(ProjectSuite, ChangeName) {
    p.setName("New name");

    ASSERT_EQ("New name", p.getName());
}

TEST_F(ProjectSuite, Equality) {
    ASSERT_TRUE(p == q);
}

TEST_F(ProjectSuite, GetTask){
    ASSERT_NO_FATAL_FAILURE(Task* t = p.getTask(-1));
    ASSERT_EQ(p.getTask(-1), p.tasks.end()->second);
    //Map::find returns an iterator to Map::end if not found.
    //Comparing a Task* object to the Task* pointer of Map::end,it does work,but is it the best solution?
}
