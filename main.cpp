#include <iostream>
#include <QApplication>
#include <ctime>

#include "Model.h"
#include "Controller.h"
#include "View.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    // current date/time based on current system
    /*time_t now = time(nullptr);

    std::cout << "Number of sec since January 1,1970:" << now << std::endl;
    tm *ltm = localtime(&now);

    // print various components of tm structure.
    std::cout << "Year" << 1900 + ltm->tm_year<< std::endl;
    std::cout << "Month: "<< 1 + ltm->tm_mon<<  std::endl;
     std::cout << "Day: "<<  ltm->tm_mday <<  std::endl;
     std::cout << "Time: "<< 1 + ltm->tm_hour << ":";
     std::cout << 1 + ltm->tm_min << ":";
     std::cout << 1 + ltm->tm_sec <<  std::endl;*/
    Model* model = new Model;
    Controller* controller = new Controller(model);
    View view(model, controller);
    view.show();
    return app.exec();
}