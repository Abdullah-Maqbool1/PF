#include<iostream>
using namespace std;
int calculate_factorial(int* num) {
	int fact = 1;
	for (int i = 1; i <= *num; i++) {
		fact *= i;
	}
	return fact;
}
int calculate_cube(int* num) {
	return ((*num) * (*num) * (*num));
}
int calculate_square(int* num) {
	return ((*num) * (*num));
}
int main() {
	char choice, continue_choice;
	int* result = new int;
	do {
		cout << "Please select one of the following options:(a,b or c) " << endl;
		cout << " a. Calculate Factorial" << endl;
		cout << " b. Calculate Cube" << endl;
		cout << " c. Calculate Square" << endl;
		cin >> choice;
		int num;

		if (choice == 'a' || choice == 'A') {
			cout << " Enter an number: " << endl;
			cin >> num;
			int factorial = calculate_factorial(&num);
			*result = factorial;
			cout << "Factorial of " << num << " is " << *result;
			delete result;
		}
		else if (choice == 'b' || choice == 'B') {
			cout << " Enter an number: " << endl;
			cin >> num;
			int cube = calculate_cube(&num);
			*result = cube;
			cout << "Cube of " << num << " is " << *result;
			delete result;
		}
		else if (choice == 'c' || choice == 'C') {
			cout << " Enter an number: " << endl;
			cin >> num;
			int square = calculate_square(&num);
			*result = square;
			cout << "Square of " << num << " is " << *result;
			delete result;
		}
		else {
			cout << "Incorrect input";
		}
		cout << "\nPress Y to continue \n Press 'E' to exit! " << endl;
		cin >> continue_choice;
	} while (continue_choice == 'Y' || continue_choice == 'y');
	return 0;
}