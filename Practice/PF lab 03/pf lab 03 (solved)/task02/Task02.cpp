#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("task02__input.txt");
    ofstream output("task02__output.txt");

    char ch_combination[] = "abcde";
    char line[100];
    int lineNumber = 0;

    cout << "Occurrences of " << ch_combination << ":\n";

    while (input.getline(line, sizeof(line))) {
        lineNumber++;
        int occurrences = 0;

        for (int j = 0; line[j] != '\0'; j++) {
            bool match = true;
            for (int i = 0; ch_combination[i] != '\0'; i++) {
                if (line[j + i] != ch_combination[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                occurrences++;
            }
        }

        if (occurrences > 0) {
            cout << lineNumber << ": " << occurrences << endl;
            output << lineNumber << ": " << line << ", Occurrences: " << occurrences << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}