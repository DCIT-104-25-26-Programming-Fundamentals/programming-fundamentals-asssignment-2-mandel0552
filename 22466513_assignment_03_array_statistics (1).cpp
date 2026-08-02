#include <iostream>
using namespace std;

// Returns the sum of all values in `arr` without using accumulate().
int calculateSum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// Returns the average of all values in `arr`.
double calculateAverage(int arr[], int n) {
    // Reuse calculateSum() rather than recalculating the total manually
    return static_cast<double>(calculateSum(arr, n)) / n;
}

// Returns the largest value in `arr` without using max().
int calculateMax(int arr[], int n) {
    int largest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Returns the smallest value in `arr` without using min().
int calculateMin(int arr[], int n) {
    int smallest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (cin.fail()) {
        cout << "Error: Please enter a valid whole number." << endl;
        return 1;
    }

    // N must be a positive integer
    if (n <= 0) {
        cout << "Error: The number of values must be a positive integer." << endl;
        return 1;
    }

    // Dynamically allocate an array of size n
    int* numbers = new int[n];

    // Collect the numbers from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Compute each statistic using its own function
    int total = calculateSum(numbers, n);
    double average = calculateAverage(numbers, n);
    int highest = calculateMax(numbers, n);
    int lowest = calculateMin(numbers, n);

    // Display the results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << highest << endl;
    cout << "Minimum: " << lowest << endl;

    // Free the dynamically allocated memory
    delete[] numbers;

    return 0;
}
