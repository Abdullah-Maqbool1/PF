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
	cout << "Matrix in column wise: " << endl;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << arr[j][i] << "  ";
		}
		cout << endl;

	}
	return 0;
}