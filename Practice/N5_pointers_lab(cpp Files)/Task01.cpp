#include<iostream>
using namespace std;
int main() {
    int num1, num2;
    cout << "Enter the value of Num1: " << endl;
    cin >> num1;
    cout << "Enter the value of Num2: " << endl;
    cin >> num2;
    int* ptrN1 = &num1;
    int* ptrN2 = &num2;

    cout << "Value of num1 is: " << *ptrN1 << endl;
    cout << "Value of num2 is: " << *ptrN2 << endl;
    cout << endl;
    cout << "Addreas of num1 is: " << ptrN1 << endl;
    cout << "Addreas of num2 is: " << ptrN2 << endl;
    cout << endl;
    cout << "Value of PointerN1 is: " << ptrN1 << endl;
    cout << "Value of PointerN2 is: " << ptrN1 << endl;
    cout << endl;
    (*ptrN1)++;
    (*ptrN2)--;
    cout << "Value of PointerN1 after increment is: " << *ptrN1 << endl;
    cout << "Value of PointerN2 after increment is: " << *ptrN2 << endl;
    return 0;
}