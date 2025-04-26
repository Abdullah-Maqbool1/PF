#include<iostream>
using namespace std;
void regrowINTarray(char*& old_array, int& oldsize, int new_size) {
	char* new_array = new char[new_size];
	for (int i = 0; i < new_size; i++) {	
			new_array[i] = old_array[i];
	}
	cout << "Array elements after Shrinking: " << endl;
	for (int i = 0; i < new_size; i++) {
		cout << new_array[i] << " ";
	}
}
int main() {
	int old_size;
	cout << "Enter the size of dynamic character array: ";
	cin >> old_size;
	char* old_arr = new char[old_size];
	cout << "Enter the alphabets to store at old array: " << endl;
	for (int i = 0; i < old_size; i++) {
		cin >> old_arr[i];
	}
	int new_size;
	cout << "Enter the new size of new array: " << endl;
	cin >> new_size;
	regrowINTarray(old_arr, old_size, new_size);
	delete[]old_arr;
	return 0;
}