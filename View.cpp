//
// Created by Dario on 03/03/2019.
//

#include "View.h"

View::View(Model* m, Controller* c, QWidget* parent, ViewWindow *v) : QMainWindow(parent), ui(new Ui::MainWindow), model(m), controller(c), vw(v) {
    model->subscribe(this);
    ui->setupUi(this);
    update();
}
View::~View() {
    model->unsubscribe(this);
    delete ui;
}

void View::update() {
    int it = 0;
    //std::string projectError = model->getProjectError();
    //ui->projectError->setText(QString::fromStdString(projectError));
    //Clear every record in inputs and lists
    ui->projectCombo->clear();
    ui->projectList->clear();
    ui->taskList->setRowCount(0);
    //setto la data di inizio e fine al momento corrente
    ui->taskStart->setDateTime(QDateTime::currentDateTime());
    ui->taskEnd->setDateTime(QDateTime::currentDateTime());
    //Iterate over Model's project list and update inputs and lists
    //Iterate every task of each project
    for (auto pr_it = model->projects.begin(); pr_it != model->projects.end(); ++pr_it){
        ui->projectCombo->addItem(QString::fromStdString((*pr_it)->getName()));
        ui->projectList->addItem(QString::fromStdString((*pr_it)->getName()));
        for(auto t_it = (*pr_it)->tasks.begin(); t_it != (*pr_it)->tasks.end(); ++t_it){

            ui->taskList->insertRow(it);
            ui->taskList->setItem(it, 0, new QTableWidgetItem(QObject::tr("%1").arg(
                    QString::fromStdString((*t_it)->getName()))));
            ui->taskList->setItem(it, 1, new QTableWidgetItem(QObject::tr("%1").arg(
                    QString::fromStdString(((*pr_it)->getName())))));
            ui->taskList->setItem(it, 2, new QTableWidgetItem(QObject::tr("%1").arg(
                    (*t_it)->getTaskStart().toString("dd/MM/yyyy"))));
            ui->taskList->setItem(it, 3, new QTableWidgetItem(QObject::tr("%1").arg(
                    (*t_it)->getTaskStart().toString("hh:mm"))));
            ui->taskList->setItem(it, 4, new QTableWidgetItem(QObject::tr("%1").arg(
                    (*t_it)->getTaskEnd().toString("hh:mm"))));
            QPushButton* taskRemove = new QPushButton();
            taskRemove->setObjectName(QStringLiteral("taskRemove"));
            taskRemove->setText("Delete");
            ui->taskList->setCellWidget(it, 5, taskRemove);
            QObject::connect(taskRemove, SIGNAL(clicked()), this, SLOT(on_taskRemove_clicked()));
            it++;
        }
    }

    updateDashboard(ui->dateFromFilter->dateTime(),ui->dateToFilter->dateTime());

    if(ui->projectList->currentItem() != nullptr){
        ui->projectInput->setText(ui->projectList->currentItem()->text().toUtf8().constData());
        ui->projectRemove->setEnabled(true);
        ui->projectUpdate->setEnabled(false);
    }

    else{
        ui->projectInput->clear();
        ui->projectRemove->setEnabled(false);
        ui->projectUpdate->setEnabled(false);
    }
}

void View::updateDashboard(QDateTime from,QDateTime to) {
    qint64 duration;
    int it = 0;
    ui->dashboardWidegt->setRowCount(0);
    //TODO: move sum function in controller
    for (auto pr_it = model->projects.begin(); pr_it != model->projects.end(); ++pr_it){
        duration = 0;
        for(auto t_it = (*pr_it)->tasks.begin(); t_it != (*pr_it)->tasks.end(); ++t_it){
            if((*t_it)->getTaskStart() >= from and (*t_it)->getTaskStart() <= to)
                duration += (*t_it)->getTaskStart().secsTo((*t_it)->getTaskEnd());
        }
        if(duration != 0){
            ui->dashboardWidegt->insertRow(it);
            ui->taskList->setItem(it, 0, new QTableWidgetItem(QObject::tr("%1").arg(
                    QString::fromStdString(((*pr_it)->getName())))));
            ui->dashboardWidegt->setItem(it, 1, new QTableWidgetItem(QObject::tr("%1").arg(
                    controller->secondsToTime(duration).toString("hh:mm"))));
            it ++;
        }
    }
}

QTime View::getDuration(QDateTime from,QDateTime to){
    return controller->secondsToTime(from.secsTo(to));
}

void View::on_projectSubmit_clicked() {
    //TODO: handle duplicates
    std::string name = ui->projectInput->text().toUtf8().constData();

    controller->createProject(name);
    ui->projectInput->clear();
}

void View::on_taskSubmit_clicked(){
    std::string taskName = ui->taskName->text().toUtf8().constData();
    std::string projectName = ui->projectCombo->currentText().toUtf8().constData();
    //std::cout << "View project:" << projectName <<std::endl;
    controller->addTaskToProject(projectName,taskName,ui->taskStart->dateTime(),ui->taskEnd->dateTime());
}

void View::on_projectUpdate_clicked(){
    std::string newName = ui->projectInput->text().toUtf8().constData();
    std::string oldName;
    if(ui->projectList->currentItem() != nullptr){
        oldName = ui->projectList->currentItem()->text().toUtf8().constData();
        controller->updateProject(oldName,newName);
    }
}

void View::on_projectRemove_clicked(){
    //std::cout << "Remove project clicked" << std::endl;
    std::string projectName;
    if(ui->projectList->currentItem() != nullptr){
        projectName = ui->projectList->currentItem()->text().toUtf8().constData();
        controller->removeProject(projectName);
    }
}

void View::on_projectList_itemSelectionChanged()
{
    if(ui->projectList->currentItem() != nullptr){
        ui->projectInput->setText(ui->projectList->currentItem()->text().toUtf8().constData());
        ui->projectRemove->setEnabled(true);
        ui->projectUpdate->setEnabled(true);
    }

}

void View::on_taskRemove_clicked() {
    //HACK: a combination of taskName and taskProject is not the best way to retrieve data from model.
    std::string taskName;
    std::string projectName;
    std::cout <<"Remove task clicked" << std::endl;
    QWidget *w = qobject_cast<QWidget *>(sender()->parent());
    if(w){
        int row = ui->taskList->indexAt(w->pos()).row();
        taskName = ui->taskList->item(row,0)->text().toUtf8().constData();
        projectName = ui->taskList->item(row,1)->text().toUtf8().constData();
        std::cout << "Row name: " << taskName << std::endl;
        controller->removeTaskFromProject(projectName,taskName);
    }
}