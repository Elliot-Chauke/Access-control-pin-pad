#include "Gate.h"

// Constructor: Initializes the gate's description and password.
Gate::Gate(const QString &d, int p) : description(d), password(p) {}

// Returns the description of the gate.
QString Gate::getDescription() const {
    return description;
}

// Checks if the provided password matches the gate's password.
bool Gate::checkPassword(int p) const {
    return p == password;
}
