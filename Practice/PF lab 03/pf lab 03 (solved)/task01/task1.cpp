#include<iostream>
#include<fstream>
#include<cstring>
#define size 30
using namespace std;
int main() {

    //creating arrays to store words from files:
    char arr1[size];
    char arr2[size];

    //creating files:
    ifstream read("task01_input.txt");
    ifstream dictionary("dictionary.txt");

    //printing misspelled words: 
    cout << "Following are the misspelled words in the file: " << endl;
    while (!read.eof()) {
        while (!read.eof()) {
            read.getline(arr1, size, ' ');
            break;
        }
        while (!dictionary.eof()) {
            dictionary.getline(arr2, size, '\n');
            break;
        }

        //comparing arrays:
        int i = strcmp(arr1, arr2);

        if (i != 0) {

            //printing on console:
            cout << arr1 << "\n";

        }
    }
    read.close();
    dictionary.close();

    return 0;
}