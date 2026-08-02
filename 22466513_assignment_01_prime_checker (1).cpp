#include <iostream>
using namespace std;

// Returns true if `number` is a prime number, false otherwise.
bool isPrime(int number) {
    // Numbers less than 2 are never prime
    if (number < 2) {
        return false;
    }

    // 2 is the only even prime number
    if (number == 2) {
        return true;
    }

    // Eliminate other even numbers quickly
    if (number % 2 == 0) {
        return false;
    }

    // Check odd divisors up to the square root of the number.
    // If no divisor is found, the number is prime.
    for (int divisor = 3; divisor * divisor <= number; divisor += 2) {
        if (number % divisor == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    // Handle invalid (non-integer) input gracefully
    if (cin.fail()) {
        cout << "Please enter a valid whole number." << endl;
        return 1;
    }

    // Call the function and print the appropriate result
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }

    return 0;
}
