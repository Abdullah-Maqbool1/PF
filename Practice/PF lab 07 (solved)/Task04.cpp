// Calculating sum from 2 files:
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");
    ofstream output("output_sum.txt");

    int* arr1 = new int[1];
    int* arr2 = new int[1];
    int* sum = new int[1];

    int size1 = 0;
    int size2 = 0;

    int num;

    // Reading file1 and storing numbers in arr1:
    while (file1 >> num) {
        if (size1 >= 1) {
            int* temp = new int[size1 * 2];
            for (int i = 0; i < size1; i++) {
                temp[i] = arr1[i];
            }
            delete[] arr1;
            arr1 = temp;
        }
        arr1[size1++] = num;
    }

    // Reading file2 and storing numbers in arr2
    while (file2 >> num) {
        if (size2 >= 1) {
            int* temp = new int[size2 * 2];
            for (int i = 0; i < size2; i++) {
                temp[i] = arr2[i];
            }
            delete[] arr2;
            arr2 = temp;
        }
        arr2[size2++] = num;
    }


    // Calculating sum and storing in sum array:
    for (int i = 0; i < size1; i++) {
        sum[i] = arr1[i];
        sum[i] += arr2[i];
    }

    // Writing sum in the output file:
    for (int i = 0; i < size1; i++) {
        output << sum[i] << " ";
    }

    delete[] arr1;
    delete[] arr2;
    delete[] sum;

    return 0;
}