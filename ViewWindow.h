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
#include <QMenuBar>
#include <QAction>
#include <QObject>
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
    /*QPushButton *submitButton;
    QLabel *taskLabel;
    QLineEdit *taskInput;
    QLabel *taskDateLabel;
    QDateTimeEdit *taskDate;*/
    void setupUi(QMainWindow *View) {
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("ViewWindow"));
        View->resize(400, 300);
        //Main widget
        ViewWidget = new QWidget(View);
        ViewWidget->setObjectName(QStringLiteral("ViewWidget"));
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
        comboLabel = new QLabel(ViewWidget);
        comboLabel->setObjectName(QStringLiteral("comboLabel"));
        projectCombo = new QComboBox(ViewWidget);
        projectCombo->setObjectName(QStringLiteral("projectCombo"));
        formLayout->addRow(projectLabel,projectInput);
        formLayout->addRow(projectError,submitProject);
        formLayout->addRow(comboLabel,projectCombo);
        //projectError->setGeometry(QRect(20, 130, 100, 21));
        //Button to save and store Task Data
        /*submitButton = new QPushButton(ViewWidget);
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
        //taskDate->setDisplayFormat("MMM d yyyy");*/
        ViewWidget->setLayout(formLayout);
        View->setCentralWidget(ViewWidget);

        retranslateUi(View);
        QObject::connect(submitProject, SIGNAL(clicked()), View, SLOT(onCreateProject()));

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View) {
        View->setWindowTitle(QObject::tr("ActivityTracker"));
        submitProject->setText(QApplication::translate("ViewWidget", "Create Project", nullptr));
        projectLabel->setText(QApplication::translate("ViewWidget", "Project Name", nullptr));
        comboLabel->setText(QApplication::translate("ViewWidget","Project", nullptr));
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
