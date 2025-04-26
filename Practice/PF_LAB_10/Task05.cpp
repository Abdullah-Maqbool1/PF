#include<iostream>
using namespace std;

int main() {
    int row, col;
    int arr[20][20];

    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;

    cout << "Enter the elements of matrix: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter an element to store at index [" << i << "," << j << "]: ";
            cin >> arr[i][j];
        }
        cout << endl;
    }

    cout << "Matrix before sorting: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout <<"\t" << arr[i][j] << " ";
        }
        cout << endl;
    }

    int temp;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col - 1; j++) {
            for (int k = 0; k < col - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }

    cout << "Matrix After sorting: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout <<"\t" << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
