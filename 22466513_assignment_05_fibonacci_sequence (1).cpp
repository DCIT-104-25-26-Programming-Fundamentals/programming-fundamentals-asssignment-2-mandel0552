#include <iostream>
using namespace std;

// Prints the first n Fibonacci terms on one line, separated by spaces.
// Uses a loop (no recursion).
void printFirstNTerms(int n) {
    long a = 0, b = 1;

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i != n - 1) {
            cout << " ";
        }
        long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

// Returns true if `number` appears in the Fibonacci sequence, false otherwise.
// Uses a loop to generate terms up to `number`.
bool isFibonacci(long number) {
    if (number < 0) {
        return false;
    }

    long a = 0, b = 1;
    while (a < number) {
        long next = a + b;
        a = b;
        b = next;
    }

    return a == number;
}

// Part A: ask for N and print the first N Fibonacci terms.
void runPrintTerms() {
    int n;
    cout << "How many terms? ";
    cin >> n;

    if (cin.fail()) {
        cout << "Error: Please enter a valid whole number." << endl;
        return;
    }

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    printFirstNTerms(n);
}

// Part B: ask for a number and report whether it's a Fibonacci number.
void runCheckMembership() {
    long number;
    cout << "Enter a number to check: ";
    cin >> number;

    if (cin.fail()) {
        cout << "Error: Please enter a valid whole number." << endl;
        return;
    }

    if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    // Part A
    runPrintTerms();

    cout << endl;

    // Part B
    runCheckMembership();

    return 0;
}
