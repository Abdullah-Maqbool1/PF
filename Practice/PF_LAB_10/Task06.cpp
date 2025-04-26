#include<iostream>
using namespace std;

void initializeName(char* name, const char* source) {
    for (int i = 0; i < 20; i++) {
        name[i] = source[i];
        if (source[i] == '\0') {
            break;
        }
    }
}

void swapNames(char* name1, char* name2) {
    char* temp = name1;
    name1 = name2;
    name2 = temp;
}

void displayName(char* name) {
    for (int i = 0; i < 20; i++) {
        cout << name[i];
        if (name[i] == '\0') {
            break;
        }
    }
    cout << endl;
}

int main() {
    const int numNames = 4;
    char** names = new char* [numNames];

    for (int i = 0; i < numNames; i++) {
        names[i] = new char[20];
    }

    initializeName(names[0], "Ali");
    initializeName(names[1], "Ahmad");
    initializeName(names[2], "Bilal");
    initializeName(names[3], "Rameel");

    cout << "List of names: " << endl;
    for (int i = 0; i < numNames; i++) {
        displayName(names[i]);
    }

    int row1, row2;
    cout << "Select 1st row to swap: " << endl;
    cin >> row1;
    cout << "Select 2nd row to swap: " << endl;
    cin >> row2;

    swapNames(names[row1], names[row2]);

    cout << "\n\n\t UPDATED list of names: " << endl;
    for (int i = 0; i < numNames; i++) {
        displayName(names[i]);
    }

    // Deallocate memory
    for (int i = 0; i < numNames; i++) {
        delete[] names[i];
    }
    delete[] names;

    return 0;
}