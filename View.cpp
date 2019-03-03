//
// Created by Dario on 03/03/2019.
//

#include "View.h"

View::~View() {
    model->removeObserver(this);
}

void View::update() {
    QWidget::update();
}

View::View(Model *m, Controller *c, QWidget *parent) : QMainWindow(parent), model(m), controller(c) {
    model->addObserver(this);
    update();
}
