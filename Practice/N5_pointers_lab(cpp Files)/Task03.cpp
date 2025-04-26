
#include<iostream>
using namespace std;

void swap_numbers(int* ptrN1, int* ptrN2, int* ptrN3) {
    int temp = *ptrN1;
    *ptrN1 = *ptrN2;
    *ptrN2 = *ptrN3;
    *ptrN3 = temp;
}

int main() {
    int num1, num2, num3;
    cout << "Enter Num1: " << endl;
    cin >> num1;
    cout << "Enter Num2: " << endl;
    cin >> num2;
    cout << "Enter Num3: " << endl;
    cin >> num3;
    int* ptrN1 = &num1;
    int* ptrN2 = &num2;
    int* ptrN3 = &num3;
    cout << "Before Swapping: " << endl;
    cout << "Num1 = " << num1 << endl;
    cout << "Num2 = " << num2 << endl;
    cout << "Num3 = " << num3 << endl;
    swap_numbers(ptrN1, ptrN2, ptrN3);
    cout << "After Swapping: " << endl;
    cout << "Num1 = " << num1 << endl;
    cout << "Num2 = " << num2 << endl;
    cout << "Num3 = " << num3 << endl;
    return 0;
}