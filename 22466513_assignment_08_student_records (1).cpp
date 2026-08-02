#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;

// Represents one student record.
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Returns the average of `scores`.
double calculateAverage(const vector<double> &scores) {
    double total = 0;
    for (double score : scores) {
        total += score;
    }
    return total / scores.size();
}

// Formats a score without a trailing ".0" for whole numbers.
string formatScore(double score) {
    if (score == static_cast<int>(score)) {
        return to_string(static_cast<int>(score));
    }
    ostringstream oss;
    oss << score;
    return oss.str();
}

// Formats a number to exactly 2 decimal places as a string.
string formatAverage(double average) {
    ostringstream oss;
    oss << fixed << setprecision(2) << average;
    return oss.str();
}

// Asks for a student's name, ID, and scores, then saves the record.
void addStudent(vector<Student> &students) {
    Student s;

    // Clear any leftover newline from a previous cin >> before using getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Student ID must be a valid whole number." << endl;
        return;
    }

    cout << "How many scores? ";
    int count;
    cin >> count;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Please enter a valid whole number." << endl;
        return;
    }
    if (count <= 0) {
        cout << "Error: Number of scores must be a positive integer." << endl;
        return;
    }

    for (int i = 1; i <= count; i++) {
        cout << "Enter score " << i << ": ";
        double score;
        cin >> score;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Scores must be valid numbers. Student not added." << endl;
            return;
        }
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

// Prints a formatted table of every student's name, ID, scores, and average.
void displayAllStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    string separator(50, '-');
    cout << separator << endl;
    cout << left << setw(15) << "Name" << setw(12) << "ID"
         << setw(15) << "Scores" << setw(10) << "Average" << endl;
    cout << separator << endl;

    for (const Student &student : students) {
        string scoresStr;
        for (size_t i = 0; i < student.scores.size(); i++) {
            scoresStr += formatScore(student.scores[i]);
            if (i != student.scores.size() - 1) {
                scoresStr += ", ";
            }
        }

        double average = calculateAverage(student.scores);

        cout << left << setw(15) << student.name << setw(12) << student.id
             << setw(15) << scoresStr << formatAverage(average) << endl;
    }

    cout << separator << endl;
}

// Looks up a student by ID and prints their average score.
void findStudentAverage(const vector<Student> &students) {
    cout << "Enter student ID: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Please enter a valid ID number." << endl;
        return;
    }

    for (const Student &student : students) {
        if (student.id == id) {
            double average = calculateAverage(student.scores);
            cout << student.name << "'s average score: "
                 << formatAverage(average) << endl;
            return;
        }
    }

    cout << "Error: No student found with that ID." << endl;
}

// Displays the student record system menu.
void printMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<Student> students;

    while (true) {
        printMenu();
        cout << "Enter your choice (1-4): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please choose a number between 1 and 4." << endl;
            cout << endl;
            continue;
        }

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            findStudentAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please choose a number between 1 and 4." << endl;
        }

        cout << endl;
    }

    return 0;
}
