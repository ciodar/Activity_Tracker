//
// Created by Dario on 21/03/2019.
//

#include "ViewWindow.h"

void ViewWindow::setupActions(QMainWindow *View) {
    QMetaObject::connectSlotsByName(View);
}