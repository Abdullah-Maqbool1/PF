#include<iostream>
using namespace std;
void histo(int* ptr_element[], int i) {
    int element_number = i;
    int value = *ptr_element[i];
    cout << "\tElement Number: " << element_number << "\tValue: " << value << "\tHistogram = ";
    for (int i = 0;i < value;i++) {
        cout << "*";
    }
}
int main() {
    cout << "Enter 10 Elements: " << endl;
    int elements[10];
    int* ptr[10];
    for (int i = 1;i <= 10;i++) {
        cout << "Element" << i << " = ";
        cin >> elements[i];
        ptr[i] = &elements[i];
    }
    for (int i = 1;i <= 10;i++) {
        histo(ptr, i);
        cout << endl;
    }

    return 0;
}