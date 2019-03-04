//
// Created by Dario on 04/03/2019.
//

#ifndef ACTIVITY_TRACKER_VIEWWINDOW_H
#define ACTIVITY_TRACKER_VIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>


QT_BEGIN_NAMESPACE

class ViewWindow {
public:
    QWidget *ViewWidget;
    QPushButton *submitButton;
    QLabel *taskLabel;
    QLineEdit *taskInput;
    QLabel *taskDateLabel;
    QDateTimeEdit *taskDate;
    void setupUi(QMainWindow *View) {
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("ViewWindow"));
        View->resize(400, 300);
        //Window
        ViewWidget = new QWidget(View);
        ViewWidget->setObjectName(QStringLiteral("ViewWindow"));
        //Button to save and store Task Data
        submitButton = new QPushButton(ViewWidget);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(200, 50, 113, 32));
        //Label for Task name input
        taskLabel = new QLabel(ViewWidget);
        taskLabel->setObjectName(QStringLiteral("taskLabel"));
        taskLabel->setGeometry(QRect(20, 60, 60, 21));
        //Input for task name
        taskInput = new QLineEdit(ViewWidget);
        taskInput->setObjectName(QStringLiteral("taskInput"));
        taskInput->setGeometry(QRect(90, 60, 104, 21));
        taskInput->setAlignment(Qt::AlignLeft);
        //Label for task date
        taskDateLabel = new QLabel(ViewWidget);
        taskDateLabel->setObjectName(QStringLiteral("taskDateLabel"));
        taskDateLabel->setGeometry(QRect(20, 90, 60, 21));
        //Date input for task reference date
        //taskDate = new QDateTimeEdit;
        //taskDate->setDisplayFormat("MMM d yyyy");

        View->setCentralWidget(ViewWidget);

        retranslateUi(View);
        QObject::connect(submitButton, SIGNAL(clicked()), View, SLOT(onSubmitButton()));

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View) {
        View->setWindowTitle(QApplication::translate("ViewWindow", "ActivityTracker", nullptr));
        submitButton->setText(QApplication::translate("ViewWindow", "Create Task", nullptr));
        taskLabel->setText(QApplication::translate("ViewWindow", "Task Name", nullptr));
        taskDateLabel->setText(QApplication::translate("ViewWindow", "Date", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE


#endif //ACTIVITY_TRACKER_VIEWWINDOW_H
