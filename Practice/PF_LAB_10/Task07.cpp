#include <iostream>
using namespace std;
int main() {
    char firstNames[4][20] = { "Ali", "Bilal", "Ahmad", "Muhammad" };
    char lastNames[4][20] = { "Haider", "Ijaz", "Raza", "Rameel" };
    char fullNames[4][40];

    for (int i = 0; i < 4; i++) {
        int j = 0;
        while (firstNames[i][j] != '\0') {
            fullNames[i][j] = firstNames[i][j];
            j++;
        }
        fullNames[i][j] = ' ';
        j++;
        int k = 0;
        while (lastNames[i][k] != '\0') {
            fullNames[i][j] = lastNames[i][k];
            j++;
            k++;
        }
        fullNames[i][j] = '\0';
    }

    cout << "List of Full Names:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << fullNames[i] << endl;
    }

    return 0;
}
