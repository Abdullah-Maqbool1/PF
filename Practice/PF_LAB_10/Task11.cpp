#include <iostream>
using namespace std;
bool compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return true;
        }
        else if (str1[i] > str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0';
}
void swapStrings(char str1[], char str2[]) {
    int i = 0;
    char temp;
    while (str1[i] != '\0' || str2[i] != '\0') {
        temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;
        i++;
    }
}

int main() {
    const int MAX_NAMES = 100;
    char names[MAX_NAMES][50];

    int numNames;
    cout << "Enter the number of names (limit " << MAX_NAMES << "): ";
    cin >> numNames;
    if (numNames <= 0 || numNames > MAX_NAMES) {
        cerr << "Error: Invalid number of names. Please enter a value between 1 and " << MAX_NAMES << endl;
        return 1;
    }
    cout << "Enter " << numNames << " names:\n";
    for (int i = 0; i < numNames; i++) {
        cin >> names[i];
    }
    for (int i = 0; i < numNames - 1; i++) {
        for (int j = 0; j < numNames - i - 1; j++) {
            if (compareStrings(names[j], names[j + 1])) {
                swapStrings(names[j], names[j + 1]);
            }
        }
    }
    cout << "\nList of Sorted Names:\n";
    for (int i = 0; i < numNames; i++) {
        cout << names[i] << endl;
    }

    return 0;
}
