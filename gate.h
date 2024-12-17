#ifndef GATE_H
#define GATE_H

#include <QString>

class Gate {
public:
    // Constructor that initializes the description and password of the gate
    Gate(const QString &d, int p);

    // Function to get the description of the gate
    QString getDescription() const;

    // Function to check if the provided password is correct
    bool checkPassword(int p) const;

private:
    QString description; // Stores the description of the gate
    int password;        // Stores the password of the gate
};

#endif // GATE_H
