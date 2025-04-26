#include<iostream>
int main() {
    int** ptr = new int* [2];
    ptr[0] = new int(5);
    ptr[1] = new int(10);
    delete ptr[0];
    std::cout << *ptr[1] << std::endl;
    return 0;
}