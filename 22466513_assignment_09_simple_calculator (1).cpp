#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <limits>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

// Returns true and stores a / b in `result`, or false if b is zero.
bool divide(double a, double b, double &result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

// Returns true and stores a % b in `result`, or false if b is zero.
bool computeModulus(double a, double b, double &result) {
    if (b == 0) {
        return false;
    }
    result = fmod(a, b);
    return true;
}

double exponentiate(double a, double b) {
    return pow(a, b);
}

// Formats a number to exactly 2 decimal places as a string.
string formatFixed2(double value) {
    ostringstream oss;
    oss << fixed << setprecision(2) << value;
    return oss.str();
}

// Formats a number without a trailing ".0" for whole numbers.
string formatPlain(double value) {
    if (value == static_cast<long long>(value)) {
        return to_string(static_cast<long long>(value));
    }
    ostringstream oss;
    oss << value;
    return oss.str();
}

// Asks for two numbers, performs the chosen operation, and prints the result.
void performOperation(int choice) {
    double a, b;

    cout << "Enter first number : ";
    cin >> a;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Please enter a valid number." << endl;
        return;
    }

    cout << "Enter second number: ";
    cin >> b;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Please enter a valid number." << endl;
        return;
    }

    double result = 0;
    bool ok = true;
    string symbol;

    if (choice == 1) {
        result = add(a, b);
        symbol = "+";
    } else if (choice == 2) {
        result = subtract(a, b);
        symbol = "-";
    } else if (choice == 3) {
        result = multiply(a, b);
        symbol = "*";
    } else if (choice == 4) {
        ok = divide(a, b, result);
        symbol = "/";
    } else if (choice == 5) {
        ok = computeModulus(a, b, result);
        symbol = "%";
    } else if (choice == 6) {
        result = exponentiate(a, b);
        symbol = "^";
    }

    if (!ok) {
        if (choice == 4) {
            cout << "Error: Cannot divide by zero." << endl;
        } else {
            cout << "Error: Cannot perform modulus with zero." << endl;
        }
        return;
    }

    cout << "Result: " << formatPlain(a) << " " << symbol << " "
         << formatPlain(b) << " = " << formatFixed2(result) << endl;
}

// Displays the calculator menu.
void printMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    while (true) {
        printMenu();
        cout << "Select an operation (1-7): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please choose a number between 1 and 7." << endl;
            cout << endl;
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        } else if (choice >= 1 && choice <= 6) {
            performOperation(choice);
        } else {
            cout << "Error: Please choose a number between 1 and 7." << endl;
        }

        cout << endl;
    }

    return 0;
}
