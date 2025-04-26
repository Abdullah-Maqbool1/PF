#include <iostream>
#include <cstring>
#define size 50
using namespace std;
void TextCompare(int* X, int* Y, int X_len, int Y_len) {
    for (int i = 0; i < X_len - 1; i++) {
        if (X[i] == Y[i]) {
            cout << (char)X[i] << " ";
        }
        else if (X[i] != Y[i]) {
            cout << "-" << (char)X[i] << " ";
        }
    }
    for (int i = 0; i < X_len; i++) {
        if (X[i] == Y[i] && i >= X_len - 1) {
            cout << (char)Y[i];
        }
        else if (X[i] != Y[i]) {
            cout << "+" << (char)Y[i] << " ";
        }
    }
}

int main() {
    char X[size];
    char Y[size];
    int x[size];
    int y[size];
    cout << "Enter string X: ";
    cin.getline(X, size);
    cout << "Enter string Y: ";
    cin.getline(Y, size);
    //typecasting character arrays to integer arrays:
    int i = 0;
    while (X[i] != '\0') {
        x[i] = (int)X[i];
        i++;
    }
    int X_len = i;
    i = 0;
    while (Y[i] != 0) {
        y[i] = (int)Y[i];
        i++;
    }
    int Y_len = i;
    TextCompare(x, y, X_len, Y_len);
    return 0;
}