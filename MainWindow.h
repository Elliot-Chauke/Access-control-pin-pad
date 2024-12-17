#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "Gate.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    // Constructor for MainWindow, initializes the gate and GUI components
    MainWindow(QWidget *parent = 0);

    // Destructor for MainWindow
    ~MainWindow();

private slots:
    // Slot to handle button clicks (number and # buttons)
    void onButtonClicked();

    // Slot to check the password when # is pressed
    void onEnterClicked();

private:
    Gate gate;               // The gate object representing the restricted entrance
    QLineEdit *inputField;   // Hidden input field for storing the password entered
    QLabel *descriptionLabel; // Label to display the gate's description

};

#endif // MAINWINDOW_H
