#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Prompts for a task description, adds it to `tasks`, and confirms.
void addTask(vector<string> &tasks) {
    // Clear any leftover newline from a previous cin >> before using getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string task;
    cout << "Enter task: ";
    getline(cin, task);

    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

// Displays all tasks numbered from 1, or a message if empty.
void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

// Shows the tasks, asks which number to remove, then removes it.
void deleteTask(vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);

    cout << "Enter task number to delete: ";
    int index;
    cin >> index;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Please enter a valid task number." << endl;
        return;
    }

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removed = tasks[index - 1];
    tasks.erase(tasks.begin() + (index - 1));
    cout << "Task \"" << removed << "\" has been removed." << endl;
}

// Displays the to-do list menu.
void printMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<string> tasks;

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
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
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
