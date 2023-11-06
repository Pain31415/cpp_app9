#include <iostream>

using namespace std;

void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void cyclicShiftRows(int matrix[][100], int rows, int cols, int shiftCount) {
    shiftCount = shiftCount % rows;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < shiftCount; ++j) {
            int last = matrix[i][cols - 1];
            for (int k = cols - 1; k > 0; --k) {
                matrix[i][k] = matrix[i][k - 1];
            }
            matrix[i][0] = last;
        }
    }
}

int getValidInput() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail() || num <= 0) {
            cout << "Please enter a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return num;
}

int main() {
    int m, n;
    cout << "Enter the number of rows (M): ";
    m = getValidInput();
    cout << "Enter the number of columns (N): ";
    n = getValidInput();

    int matrix[100][100];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, m, n);

    cout << "Enter the number of shifts for rows to the right: ";
    int shift = getValidInput();

    cyclicShiftRows(matrix, m, n, shift);

    cout << "Matrix after cyclic shift of rows:" << endl;
    printMatrix(matrix, m, n);

    return 0;
}