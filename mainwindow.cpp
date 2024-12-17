#include "MainWindow.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStringList>
#include <QMessageBox>
#include "Gate.h"

// Constructor for MainWindow and initialize the gate and sets up the GUI layout
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), gate("Gate:\tCVV - Gate1", 0000) {

    resize(300,100); // set the size of the window

    QWidget *centralWidget = new QWidget(this); // Create a central widget for the window
    setCentralWidget(centralWidget); // Set the central widget as the main content area

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget); // Create a vertical layout for the central widget

    // Create a label to display the gate's description and add it to the main layout
    descriptionLabel = new QLabel(gate.getDescription(), this);
    mainLayout->addWidget(descriptionLabel);

    // Create a label with instructions and add it to the layout
    QLabel* instructionLabel = new QLabel("Enter password followed by #: ", this);
    mainLayout->addWidget(instructionLabel);


    // Create a grid layout for the number pad buttons (0-9 and #)
    QGridLayout *buttonLayout = new QGridLayout();

    QStringList buttons;
    // Initialize the list of buttons with numbers 0-9, and the # key
    buttons << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "#";

    int row = 0, col = 0;
    // Loop through the button list and create buttons, adding them to the grid layout
    for (int i = 0; i < buttons.size(); ++i) {
        QPushButton *button = new QPushButton(buttons[i], this); // Create a button with the corresponding label
        buttonLayout->addWidget(button, row, col); // Add the button to the grid layout
        connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked())); // Connect the button click signal to the onButtonClicked slot
        col++; // Move to the next column
        if (col == 3) { // Check if 3 buttons are added to a row, then move to the next row
            col = 0;
            row++;
        }
    }

    mainLayout->addLayout(buttonLayout); // Add the grid layout to the main layout

    // Hidden input field to store the entered password
    inputField = new QLineEdit(this);
    inputField->setEchoMode(QLineEdit::Password); // Set the input field to hide the entered text
    inputField->setVisible(false);  // Hide the input field from the user interface
}

// Destructor for MainWindow
MainWindow::~MainWindow() {}

// Slot function to handle button clicks on the number pad
void MainWindow::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender()); // Get the button that was clicked
    if (button) {
        QString text = button->text(); // Get the text of the button
        if (text == "#") {
            onEnterClicked();  // Trigger the password check when # is pressed
        } else {
            inputField->setText(inputField->text() + text);  // Append the button text to the hidden input field
        }
    }
}

// Slot function to check the password when the # key is pressed
void MainWindow::onEnterClicked() {
    bool ok;
    // Convert the entered text to an integer password
    int enteredPassword = inputField->text().toInt(&ok);
    QString message;
    // Check if the conversion was successful and the password is correct
    if (ok && gate.checkPassword(enteredPassword)) {
        message = "Access Granted"; // Set the success message
    } else {
        message = "Access Denied"; // Set the failure message
    }

    // Show the result in a second window (message box)
    QMessageBox::information(this, "Access Control", message);

    // Clear the input field for the next entry
    inputField->clear();
}
