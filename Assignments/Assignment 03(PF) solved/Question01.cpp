#include <iostream>
using namespace std;

// FUNCTION TO FIND STRING'S LENGTH:
int str_len(const char* ptr) {
    int len = 0;
    while (*ptr != '\0') {
        len++;
        ptr++;
    }
    return len;
}

// FUNCTION TO COMPARE TEXT:
void TextCompare(const char* X, const char* Y) {

    // FINDING STRING LENGTHS:
    int X_len = str_len(X);
    int Y_len = str_len(Y);

    // COMPARING STRING 'X' TO STRING 'Y':
    for (int i = 0;i < X_len - 1;i++) {
        if (X[i] == Y[i]) {
            cout << X[i] << " ";
        }
        else if (X[i] != Y[i]) {
            cout << "-" << X[i] << " ";
        }
    }
    // COMPARING STRING 'Y' TO STRING 'X':
    for (int i = 0; i < X_len; i++) {
        if (X[i] == Y[i] && i >= X_len - 1) {
            cout << Y[i];
        }
        else if (X[i] != Y[i]) {
            cout << "+" << Y[i] << " ";
        }
    }
}
int main() {
    char X[50];
    char Y[50];

    // INPUT:
    cout << "Enter string X: ";
    cin.getline(X, 50);
    cout << "Enter string Y: ";
    cin.getline(Y, 50);

    // FUNCTION:
    TextCompare(X, Y);// passing strings
    return 0;
}