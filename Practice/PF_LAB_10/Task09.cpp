#include<iostream>
using namespace std;

void sortMatrix(int** matrix, int row, int col, bool ascending) {
    int i, j, k, temp;

    // Sort each row
    for (i = 0; i < row; i++) {
        for (j = 0; j < col - 1; j++) {
            for (k = 0; k < col - j - 1; k++) {
                if (ascending) {
                    if (matrix[i][k] > matrix[i][k + 1]) {
                        temp = matrix[i][k];
                        matrix[i][k] = matrix[i][k + 1];
                        matrix[i][k + 1] = temp;
                    }
                }
                else {
                    if (matrix[i][k] < matrix[i][k + 1]) {
                        temp = matrix[i][k];
                        matrix[i][k] = matrix[i][k + 1];
                        matrix[i][k + 1] = temp;
                    }
                }
            }
        }
    }
}

int main() {
    int row, col;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    int** matrix = new int* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    bool ascending;
    cout << "Enter 1 for ascending order, 0 for descending order: ";
    cin >> ascending;

    sortMatrix(matrix, row, col, ascending);

    cout << "Sorted matrix: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}