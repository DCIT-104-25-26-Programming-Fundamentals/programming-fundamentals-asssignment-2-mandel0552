#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Prompts the user for each element of an M x N matrix, one at a time.
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Displays a matrix in a neat, aligned grid using setw().
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Computes the transpose of `matrix` (rows become columns) into `result`.
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Computes the element-wise sum of two same-sized matrices into `result`.
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Computes the matrix product a (M x N) times b (N x P) into `result` (M x P).
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int total = 0;
            for (int k = 0; k < n; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

// Prompts for and validates rows/columns as positive integers up to MAX_SIZE.
bool getDimensions(int &rows, int &cols, string label = "") {
    string suffix = label.empty() ? "" : (" for " + label);

    cout << "Enter number of rows" << suffix << ": ";
    cin >> rows;
    cout << "Enter number of columns" << suffix << ": ";
    cin >> cols;

    if (cin.fail()) {
        cout << "Error: Please enter valid whole numbers." << endl;
        return false;
    }

    if (rows <= 0 || cols <= 0) {
        cout << "Error: Rows and columns must be positive integers." << endl;
        return false;
    }

    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        cout << "Error: Rows and columns cannot exceed " << MAX_SIZE << "." << endl;
        return false;
    }

    return true;
}

void runTranspose() {
    int rows, cols;
    if (!getDimensions(rows, cols)) {
        return;
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    int result[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrix, rows, cols, result);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows);
}

void runAddition() {
    int rows, cols;
    if (!getDimensions(rows, cols, "Matrix A")) {
        return;
    }

    int matrixA[MAX_SIZE][MAX_SIZE];
    cout << "\nMatrix A:" << endl;
    readMatrix(matrixA, rows, cols);

    cout << "\nMatrix B must be the same size as Matrix A ("
         << rows << " x " << cols << ")." << endl;
    int matrixB[MAX_SIZE][MAX_SIZE];
    readMatrix(matrixB, rows, cols);

    cout << "\nMatrix A:" << endl;
    printMatrix(matrixA, rows, cols);
    cout << "\nMatrix B:" << endl;
    printMatrix(matrixB, rows, cols);

    int result[MAX_SIZE][MAX_SIZE];
    addMatrices(matrixA, matrixB, rows, cols, result);

    cout << "\nSum (A + B):" << endl;
    printMatrix(result, rows, cols);
}

void runMultiplication() {
    cout << "Matrix A (M x N):" << endl;
    int m, n;
    if (!getDimensions(m, n, "Matrix A")) {
        return;
    }

    int matrixA[MAX_SIZE][MAX_SIZE];
    readMatrix(matrixA, m, n);

    cout << "\nMatrix B must have " << n
         << " rows (to match Matrix A's columns)." << endl;
    int p;
    cout << "Enter number of columns for Matrix B: ";
    cin >> p;

    if (cin.fail() || p <= 0 || p > MAX_SIZE) {
        cout << "Error: Invalid number of columns for Matrix B." << endl;
        return;
    }

    int matrixB[MAX_SIZE][MAX_SIZE];
    readMatrix(matrixB, n, p);

    cout << "\nMatrix A:" << endl;
    printMatrix(matrixA, m, n);
    cout << "\nMatrix B:" << endl;
    printMatrix(matrixB, n, p);

    int result[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(matrixA, matrixB, m, n, p, result);

    cout << "\nProduct (A x B):" << endl;
    printMatrix(result, m, p);
}

int main() {
    cout << "Matrix Operations" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Choose an operation (1-3): ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        runTranspose();
    } else if (choice == 2) {
        runAddition();
    } else if (choice == 3) {
        runMultiplication();
    } else {
        cout << "Error: Please choose 1, 2, or 3." << endl;
    }

    return 0;
}
