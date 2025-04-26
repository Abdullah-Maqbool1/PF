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
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter an element to store at index [" << i << "," << j << "]: ";
            cin >> arr[i][j];
        }
        cout << endl;

    }
    cout << " Average row-wise: ";
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
        cout << sum << ",";
    }
    cout << endl;
    cout << " Average column-wise: ";
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += arr[i][j];
        }
        cout << sum << ",";
    }

    return 0;
}