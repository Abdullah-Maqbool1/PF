//Match data:
#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;
bool isNumeric(char* word) {
    while (*word != '\0') {
        if (*word < '0' || *word > '9') {
            return false;
        }
        ++word;
    }
    return true;
}

int main() {
    const int MAX_WORD_LENGTH = 100;
    char word1[MAX_WORD_LENGTH];
    char word2[MAX_WORD_LENGTH];

    ifstream file1("Task5_File1.txt");
    ifstream file2("Task5_File2.txt");

    bool match = true;
    int count1 = 0, count2 = 0;

    while (file1 >> word1 && file2 >> word2) {
        if (strcmp(word1, word2) != 0) {
            match = false;
        }

        if (!isNumeric(word1)) {
            ++count1;
        }

        if (!isNumeric(word2)) {
            ++count2;
        }
    }

    if (file1.eof() != file2.eof()) {
        match = false;
    }

    if (match) {
        cout << "TRUE" << endl;
    }
    else {
        cout << "FALSE" << endl;
    }

    cout << "File1 non-numeric words: " << count1 << endl;
    cout << "File2 non-numeric words: " << count2 << endl;

    file1.close();
    file2.close();
    return 0;
}