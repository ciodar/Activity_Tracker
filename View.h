//
// Created by Dario on 03/03/2019.
//

#ifndef ACTIVITY_TRACKER_VIEW_H
#define ACTIVITY_TRACKER_VIEW_H

#include <QMainWindow>
#include "Model.h"
#include "Controller.h"
#include "ViewWindow.h"
class View : public QMainWindow, public Observer {
Q_OBJECT
public:
    View(Model* m, Controller* c, QWidget *parent = nullptr);
    ~View();
    virtual void update() override;
private slots:

private:
    ViewWindow* ui;
    Model* model;
    Controller* controller;
};


#endif //ACTIVITY_TRACKER_VIEW_H
