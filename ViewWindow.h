//
// Created by Dario on 04/03/2019.
//

#ifndef ACTIVITY_TRACKER_VIEWWINDOW_H
#define ACTIVITY_TRACKER_VIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QMenuBar>
#include <QAction>
#include <QObject>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class ViewWindow {
public:
    QWidget *ViewWidget;
    QFormLayout *formLayout;
    QWidget *ProjectWidget;
    QMenu *projectMenu;

    QAction *newProj;

    QLabel *projectLabel;
    QLineEdit *projectInput;
    QPushButton *submitProject;
    QLabel *projectError;
    QLabel *comboLabel;
    QComboBox *projectCombo;
    QLabel *taskLabel;
    QLineEdit *taskInput;
    QLabel *taskStartDateLabel;
    QDateTimeEdit *taskStartDate;
    QLabel *taskEndDateLabel;
    QDateTimeEdit *taskEndDate;
    QPushButton *submitTask;
    QTableView *viewTask;
    void setupUi(QMainWindow *View) {
        //TODO Refactor the view and add containers for single form functions
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("ViewWindow"));
        View->resize(800, 600);
        //Main widget
        ViewWidget = new QWidget(View);
        ViewWidget->setObjectName(QStringLiteral("ViewWidget"));
        //Layout of the fields. Consists in a grid with a label and an input.
        formLayout = new QFormLayout;
        createMenus(View);
        createActions(View);
        //ProjectWidget = new QWidget(View);
        //ProjectWidget->setObjectName(QStringLiteral("ProjectWidget"));
        //Label for Task name input
        projectLabel = new QLabel(ViewWidget);
        projectLabel->setObjectName(QStringLiteral("projectLabel"));
        //projectLabel->setGeometry(QRect(20, 60, 70, 21));
        //Input for task name
        projectInput = new QLineEdit(ViewWidget);
        projectInput->setObjectName(QStringLiteral("projectInput"));
        //projectInput->setGeometry(QRect(100, 60, 104, 21));
        projectInput->setAlignment(Qt::AlignLeft);
        //Button to submit
        submitProject = new QPushButton(ViewWidget);
        submitProject->setObjectName(QStringLiteral("submitProject"));
        //submitProject->setGeometry(QRect(200, 50, 113, 32));
        //Error message
        projectError = new QLabel(ViewWidget);
        projectError->setObjectName(QStringLiteral("projectError"));
        //-----PROJECT END -----
        //-----TASK START -----
        //label for projects dropdown
        comboLabel = new QLabel(ViewWidget);
        comboLabel->setObjectName(QStringLiteral("comboLabel"));
        //Dropdown input with the names of the projects
        projectCombo = new QComboBox(ViewWidget);
        projectCombo->setObjectName(QStringLiteral("projectCombo"));
        //Label for task Name
        taskLabel = new QLabel(ViewWidget);
        taskLabel->setObjectName(QStringLiteral("taskLabel"));
        //Task name input
        taskInput = new QLineEdit(ViewWidget);
        taskInput->setObjectName(QStringLiteral("taskInput"));
        taskStartDateLabel = new QLabel(ViewWidget);
        taskStartDateLabel->setObjectName(QStringLiteral("taskDateLabel"));
        taskStartDate = new QDateTimeEdit(ViewWidget);
        taskStartDate->setObjectName(QStringLiteral("taskStartDate"));
        taskStartDate->setDateTime(QDateTime::currentDateTime());
        taskEndDateLabel = new QLabel(ViewWidget);
        taskEndDateLabel->setObjectName(QStringLiteral("taskEndDateLabel"));
        taskEndDate = new QDateTimeEdit(ViewWidget);
        taskEndDate->setObjectName(QStringLiteral("taskEndDate"));
        taskEndDate->setDateTime(QDateTime::currentDateTime());
        submitTask = new QPushButton(ViewWidget);
        submitTask->setObjectName(QStringLiteral("submitTask"));
        viewTask = new QTableView(ViewWidget);
        //-----TASK END -----
        //Inserimento dei campi in layout
        formLayout->addRow(projectLabel,projectInput);
        formLayout->addRow(projectError,submitProject);
        formLayout->addRow(comboLabel,projectCombo);
        formLayout->addRow(taskLabel,taskInput);
        formLayout->addRow(taskStartDateLabel,taskStartDate);
        formLayout->addRow(taskEndDateLabel,taskEndDate);
        formLayout->addRow(submitTask);

        ViewWidget->setLayout(formLayout);
        View->setCentralWidget(ViewWidget);
        retranslateUi(View);
        QObject::connect(submitProject, SIGNAL(clicked()), View, SLOT(onCreateProject()));
        QObject::connect(submitTask, SIGNAL(clicked()), View, SLOT(onCreateTask()));

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View) {
        View->setWindowTitle(QObject::tr("ActivityTracker"));
        submitProject->setText(QApplication::translate("ViewWidget", "Create Project", nullptr));
        projectLabel->setText(QApplication::translate("ViewWidget", "Project Name", nullptr));
        comboLabel->setText(QApplication::translate("ViewWidget","Project", nullptr));
        taskLabel->setText(QApplication::translate("ViewWidget","Task Name",nullptr));
        taskStartDateLabel->setText(QApplication::translate("ViewWidget","Start", nullptr));
        taskEndDateLabel->setText(QApplication::translate("ViewWidget","End", nullptr));
        submitTask->setText(QApplication::translate("ViewWidget","Create Task", nullptr));
        newProj->setText(QObject::tr("&New"));
        newProj->setStatusTip(QObject::tr("Create a new project"));
        //taskDateLabel->setText(QApplication::translate("ViewWindow", "Date", nullptr));
    } // retranslateUi

    void createActions(QMainWindow *View) {
        newProj = new QAction(View);
        newProj->setShortcuts(QKeySequence::New);
        //QObject::connect(newProj, &QAction::triggered, View, &ViewWindow::newProject);
    }

    void createMenus(QMainWindow *View){
        projectMenu = View->menuBar()->addMenu("&Project");
        projectMenu->addAction(newProj);
    }

    void newProject(){

    }

};

QT_END_NAMESPACE


#endif //ACTIVITY_TRACKER_VIEWWINDOW_H
