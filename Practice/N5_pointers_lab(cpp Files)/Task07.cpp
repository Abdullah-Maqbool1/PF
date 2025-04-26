#include<iostream>
using namespace std;
int calculate_length(char* str_ptr,int length) {
    length++;
    return length;
}
int main() {
    char string[100];
    cout << "Enter a string: " << endl;
    cin.getline(string, 500);
    int size = 0;
    while (!string[size] == '\0') {
        size++;
    }
    int length=0;
    for (int i = 1;i <= size; i++) {
        char* str_ptr = &string[i];
        length = calculate_length(str_ptr,length);
    }
    cout << "The Length of the string is: " << length << endl;
    return 0;
}