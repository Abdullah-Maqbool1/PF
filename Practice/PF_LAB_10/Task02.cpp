#include<iostream>
using namespace std;
int main() {
	int row, col;
	int arr1[20][20];
	cout << "Enter number of rows of matrix_1: ";
	cin >> row;
	cout << "Enter number of columns of matrix_2: ";
	cin >> col;
	cout << "Enter the elements of matrix_1: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Enter an element to store in matrix_1 at index [" << i << "," << j << "]: ";
			cin >> arr1[i][j];
		}
		cout << endl;
	}
	int arr2[20][20];
	cout << "Enter number of rows of matrix_2: ";
	cin >> row;
	cout << "Enter number of columns of matrix_2: ";
	cin >> col;
	cout << "Enter the elements of matrix_2: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Enter an element to store at index [" << i << "," << j << "]: ";
			cin >> arr2[i][j];
		}
		cout << endl;
	}
	int sum[20][20];
	cout << "Sum of Matrix_1 and matrix_2: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum[i][j] = arr1[i][j] + arr2[i][j];
			
			cout<< arr1[i][j] <<" + "<< arr2[i][j] << " = " << sum[i][j] << "   ";
		}
		cout << endl;
	}
	return 0;
}
