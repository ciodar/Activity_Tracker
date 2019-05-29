# Activity_Tracker
Activity Tracker project inspired on Toggl for university exam project.
See https://toggl.com/

## Description
This application allows to track the time spent on every activity that a person does during the day.
In order to track time, a new project must be created. You can add and modify the name of the projects in every moment.
The Timer tabs allows to add a new task, specifying
* Name of the activity
* Project related to the activity
* Start date and time of the activity
* End date and time of the activity

You can insert manually your start date and time, or also use the timer button to start tracking time. 
Clicking on the start button, a timer will automatically run and start to record the time spent on your activity.
Clicking again on the button, a new task will be created with the inserted information.

You can always update the informations of every task, and also delete it.

In the dashboard tab you can see the total time spent on every project. You can change the calculation period specifying the start date 
and end date of the calculation.

## Technical specs
This Project is based on MVC model and uses QT for the GUI.
The GUI is also rendered using User interface creation provided by Qt.
Time and dates are handled using QDateTime, QTime and QDate classes.

## Installation
This program uses QT 5.9.5 version.
If QT is not found automatically, you can specify the path of QT folder using
```
CMAKE_PREFIX_PATH "[QT_DIRECTORY]\Qt\5.9.5\mingw53_32"
```
specifying the local path of QT DIRECTORY on your pc.



