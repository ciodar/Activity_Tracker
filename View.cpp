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
    std::list<Project*>::iterator pr_it;
    std::list<Task*>::iterator t_it;
    //Iterate every task of each project
    for (pr_it = model->projects.begin(); pr_it != model->projects.end(); ++pr_it){
        ui->projectCombo->addItem(QString::fromStdString((*pr_it)->getName()));
        ui->projectList->addItem(QString::fromStdString((*pr_it)->getName()));
        for(t_it = (*pr_it)->tasks.begin(); t_it != (*pr_it)->tasks.end(); ++t_it){

            ui->taskList->insertRow(it);
            ui->taskList->setItem(it, 0, new QTableWidgetItem(QObject::tr("%1").arg(
                    QString::fromStdString((*t_it)->getName()))));
            ui->taskList->setItem(it, 1, new QTableWidgetItem(QObject::tr("%1").arg(
                    QString::fromStdString(((*pr_it)->getName())))));
            ui->taskList->setItem(it, 2, new QTableWidgetItem(QObject::tr("%1").arg(
                    (*t_it)->getTaskDuration().toString("hh:mm:ss"))));
            QPushButton* taskRemove = new QPushButton();
            taskRemove->setObjectName(QStringLiteral("taskRemove"));
            taskRemove->setText("Delete");
            ui->taskList->setCellWidget(it, 3, taskRemove);
            QObject::connect(taskRemove, SIGNAL(clicked()), this, SLOT(on_taskRemove_clicked()));
            it++;
        }
    }

    if(ui->projectList->currentItem() != nullptr)
        ui->projectRemove->setEnabled(true);
    else
        ui->projectRemove->setEnabled(false);

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
    std::cout << "View project:" << projectName <<std::endl;
    controller->addTaskToProject(projectName,taskName,ui->taskStart->dateTime(),ui->taskEnd->dateTime());
    //controller->createTask()
}

void View::on_projectRemove_clicked(){
    std::cout << "Remove project clicked" << std::endl;
    std::string projectName;
    QList<QListWidgetItem*>::iterator it;
    /*for(it = ui->projectList->selectedItems().begin();it != ui->projectList->selectedItems().end(); ++it) {
        projectName = (*it)->text().toUtf8().constData();
        std::cout <<"Deleting " << projectName << std::endl;
        controller->removeProject(projectName);
    }*/
    if(ui->projectList->currentItem() != nullptr){
        projectName = ui->projectList->currentItem()->text().toUtf8().constData();
        controller->removeProject(projectName);
    }
}

void View::on_projectList_itemSelectionChanged()
{
    if(ui->projectList->currentItem() != nullptr)
        ui->projectRemove->setEnabled(true);
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