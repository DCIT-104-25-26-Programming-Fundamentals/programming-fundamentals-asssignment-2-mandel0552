#include <iostream>
using namespace std;

// Returns the letter grade corresponding to `score`.
// Returns '\0' (null character) if score is outside the valid range 0-100.
char getGrade(int score) {
    // Validate the score is within the allowed range
    if (score < 0 || score > 100) {
        return '\0';
    }

    // Determine the letter grade using if / else if / else
    if (score >= 80) {
        return 'A';
    } else if (score >= 70) {
        return 'B';
    } else if (score >= 60) {
        return 'C';
    } else if (score >= 50) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int score;

    cout << "Enter student score (0-100): ";
    cin >> score;

    // Handle invalid (non-integer) input gracefully
    if (cin.fail()) {
        cout << "Please enter a valid whole number." << endl;
        return 1;
    }

    // Call the function once, store the result, then print based on it
    char grade = getGrade(score);

    if (grade == '\0') {
        cout << "Error: Score must be between 0 and 100." << endl;
    } else {
        cout << "Grade: " << grade << endl;
    }

    return 0;
}
