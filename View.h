//
// Created by Dario on 03/03/2019.
//

#ifndef ACTIVITY_TRACKER_VIEW_H
#define ACTIVITY_TRACKER_VIEW_H

#include "Model.h"
#include "Controller.h"
#include "ui_mainwindow.h"
#include "ViewWindow.h"

#include <iostream>

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QtWidgets\QtableWidgetItem>
#include <QObject>
namespace Ui {
    class MainWindow;
}

class View : public QMainWindow, public Observer {
Q_OBJECT
public:
    explicit View(Model* m, Controller* c, QWidget *parent = nullptr, ViewWindow *vw = nullptr);
    ~View();
    virtual void update() override;

private slots:
    void on_projectSubmit_clicked();
    void on_projectUpdate_clicked();
    void on_projectRemove_clicked();
    void on_taskSubmit_clicked();
    void on_projectList_itemSelectionChanged();
    void on_taskList_cellClicked(int row, int column);
    void on_taskRemove_clicked();
    void on_taskUpdate_clicked();
private:
    void setup();
    void updateDashboard(QDateTime from,QDateTime to);
    QTime getDuration(QDateTime from,QDateTime to);
    Ui::MainWindow* ui;
    ViewWindow* vw;
    Model* model;
    Controller* controller;
};


#endif //ACTIVITY_TRACKER_VIEW_H
