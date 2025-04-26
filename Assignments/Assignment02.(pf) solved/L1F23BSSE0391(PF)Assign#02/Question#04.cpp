// C++ program that correct syntax:
#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;

void CorrectSyntax(fstream& code);
int main() {
    fstream code("Code.txt");// Creating file
    CorrectSyntax(code);
    code.close();

    return 0;
}
void CorrectSyntax(fstream& code) {
    char line[100];

    while (code.getline(line, sizeof(line))) {
        if (line[0] != '\0') {
            // Check if the line ends with a semicolon
            int len = strlen(line);
            if (line[len - 1] != ';') {
                // checking if a semicolon is required on the end of the line:
                if (line[len - 1] != ')' && line[len - 1] != '{' && line[len - 1] != '}' && line[len - 1] != '>') {
                    strcat(line, ";");
                }
            }
        }
        cout << line << endl;
    }
}
