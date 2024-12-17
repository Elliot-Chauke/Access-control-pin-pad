#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc,argv);

    MainWindow w; // Create the MainWindow object
    w.setWindowTitle("Access Control"); // Set the window title
    w.show(); // Show the main window

    return a.exec();
}
