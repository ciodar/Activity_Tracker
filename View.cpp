//
// Created by Dario on 03/03/2019.
//

#include "View.h"
#include <QStringListModel>
#include <QStringList>
View::View(Model* m, Controller* c, QWidget* parent) : QMainWindow(parent), ui(new ViewWindow()), model(m), controller(c) {
    model->subscribe(this);
    ui->setupUi(this);
    update();
}
View::~View() {
    model->unsubscribe(this);
    delete ui;
}

void View::update() {
    std::string projectError = model->getProjectError();
    ui->projectError->setText(QString::fromStdString(projectError));

    /*QStringListModel* projectsModel;
    QStringList projects;
    std::list<Project*>::iterator it;
    for (it = model->projects.begin(); it != model->projects.end(); ++it){
        projects << QString::fromStdString((*it)->getName());
    }
    projectsModel->setStringList(projects);
    ui->projectCombo->setModel(projectsModel);*/

}

void View::onCreateProject() {
    std::string name = ui->projectInput->text().toUtf8().constData();
    controller->createProject(name);
    //TODO Manage duplicated values in combo and update of values
    ui->projectCombo->addItem(QString::fromStdString(name));
    update();
}


