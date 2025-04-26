//calculate total salary: (using pointer)
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream read("sample input file.txt");
	char name[20];
	int salary;
	int sum = 0;
	int* sum_ptr;//creating pointer to sum
	
	sum_ptr = &sum;
	while (read.getline(name,20,' '))//geting name
	{ 
		//geting salary
		read >> salary;
		*sum_ptr += salary;
	}
	read.close();
	// writing in the file:
	ofstream write("OutputFile.txt");
	write << "The Total Salary: " << *sum_ptr;
	cout << "Content saved Successfully!";
	write.close();
	return 0;
}