#include<iostream>
using namespace std;
void shrinkINTarray(int*& old_array, int& oldsize, int new_size) {
	int* new_array = new int[new_size];
	for (int i = 0; i < new_size; i++) {
		
			new_array[i] = old_array[i];		
	}
	cout << "Array elements after shrinking: " << endl;
	for (int i = 0; i < new_size; i++) {
		cout << new_array[i] << " ";
	}
}
int main() {
	int old_size;
	cout << "Enter the size of old dynamic array: ";
	cin >> old_size;
	int* old_arr = new int[old_size];
	cout << "Enter the elements of old array: " << endl;
	for (int i = 0; i < old_size; i++) {
		cin >> old_arr[i];
	}
	int new_size;
	cout << "Enter the new size of new array: " << endl;
	cin >> new_size;
	shrinkINTarray(old_arr, old_size, new_size);
	delete[]old_arr;
	return 0;
}