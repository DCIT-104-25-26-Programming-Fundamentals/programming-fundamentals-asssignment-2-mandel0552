#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prints the multiplication table for `number` from 1 to 12.
void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        int product = number * i;
        cout << number << "  x  " << left << setw(2) << i
             << " =  " << product << endl;
    }
}

// Prints the multiplication table for every number from 1 to n,
// separated by a dashed line between each table.
void printTablesUpTo(int n) {
    for (int number = 1; number <= n; number++) {
        printTable(number);
        if (number != n) {
            cout << string(30, '-') << endl;
        }
    }
}

// Part A: ask for a number and print its multiplication table.
void runSingleTable() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (cin.fail()) {
        cout << "Error: Please enter a valid whole number." << endl;
        return;
    }

    printTable(number);
}

// Part B: ask for N and print tables for every number from 1 to N.
void runRangeOfTables() {
    int n;
    cout << "Enter a number (N): ";
    cin >> n;

    if (cin.fail()) {
        cout << "Error: Please enter a valid whole number." << endl;
        return;
    }

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    printTablesUpTo(n);
}

int main() {
    // Part A
    runSingleTable();

    cout << endl;

    // Part B
    runRangeOfTables();

    return 0;
}
