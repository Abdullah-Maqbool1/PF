// Question 01:
#include<iostream>
#include<fstream>
using namespace std;
int main() {

    char character;
    int count_of_words = 0;

    // Taking input of character:
    cout << "Enter a character to find words: " << endl;
    cin >> character;

    // Creating array to store words: 
    char words[100] = "\0";

    // Creating files:
    ifstream paragraph("Question.01_paragraph.txt");
    ofstream found_words("Question.01_found_words.txt");

    // Printing words starting with the entered charater:
    cout << "Words found starting with the entered character: " << endl;
    while (paragraph.getline(words, 100, (' '))) {
        for (int i = 0;i < 100;i++) {
            if ((words[i] == ',') || (words[i] == '.')) {
                words[i] = '\0';
            }
        }
        if ((words[0] == character)) {

            // Printing on console:
            cout << words << ",";

            // Printing in file:
            found_words << words << "\n";
            count_of_words++;

        }
    }

    // If no words found: 
    if (count_of_words == 0) {
        cout << "No words found!" << endl;
        found_words << "No words found!" << endl;
    }
    paragraph.close();
    found_words.close();
    return 0;
}