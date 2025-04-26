#include<iostream>
using namespace std;
int addTwoNumber(int* ptrN1, int* ptrN2) {
    return *ptrN1 + *ptrN2;

}
int main() {
    int num1, num2;
    bool incorrect_output = false;
    do {
        cout << "Enter num1: ";
        cin >> num1;
        cout << "Enter num2: ";
        cin >> num2;
        int* ptrN1 = &num1;
        int* ptrN2 = &num2;
        if (num1 >= 0 && num2 >= 0) {
            cout << "\nSum of Num1 and Num2 is: " << addTwoNumber(ptrN1, ptrN2);
        }
        else {
            cout << "\nIncorrect Input!\nTry Again: " << endl;
            incorrect_output = true;
        }
    } while (incorrect_output == true);
    return 0;
}