//
// Created by Dario on 03/03/2019.
//

#include "View.h"
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
    model->subscribe(this);
    QWidget::update();
    ui->setupUi(this);
}


