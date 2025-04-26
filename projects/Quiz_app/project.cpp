#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int NUM_QUESTIONS = 5;
const int NUM_STUDENTS = 5;

// Function to display instructions
void displayInstructions() {
    cout << "Please follow the format strictly:\n";
    cout << "1. Each question ends with a (?) sign. For example: What is your name?\n";
    cout << "2. Each choice ends with a (.) sign. For example: 1) Ali.\n";
    cout << "3. Enter only numbers for correct options (1/2/3/4).\n\n";
}

// Function to create questions and save to file
void createQuestionAnswerFile() {
    ofstream outFile("question_answer.txt");
    displayInstructions();

    char question[200];
    char choice[4][200];
    char correctAnswer;

    cin.ignore(); // To clear input buffer before taking getline

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << "Enter Question " << i + 1 << ": ";
        cin.getline(question, 200, '?');
        outFile << question << "?\n";

        for (int j = 0; j < 4; j++) {
            cout << "Enter Choice " << j + 1 << ": ";
            cin.getline(choice[j], 200, '.');
            outFile << j + 1 << ") " << choice[j] << ".\n";
        }

        cout << "Enter Correct Answer (1/2/3/4): ";
        cin >> correctAnswer;
        cin.ignore(); // to move past newline

        outFile << "Correct Answer: " << correctAnswer << "\n\n";
    }

    outFile.close();
    cout << "Questions saved to file.\n\n";
}

void startQuiz() {
    ifstream inFile("question_answer.txt");

    if (!inFile) {
        cout << "File not found. Please create the quiz first.\n";
        return;
    }

    char questions[NUM_QUESTIONS][200];
    char choices[NUM_QUESTIONS][4][200];
    char correctAnswers[NUM_QUESTIONS];

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        inFile.getline(questions[i], 200); // read question

        for (int j = 0; j < 4; j++) {
            char line[200];
            inFile.getline(line, 200);
            char* optionText = strchr(line, ' ');
            if (optionText)
                strcpy(choices[i][j], optionText + 1); // skip 'X)' and space
            else
                strcpy(choices[i][j], ""); // fallback
        }

        char line[200];
        inFile.getline(line, 200); // "Correct Answer: X"
        correctAnswers[i] = line[strlen(line) - 1]; // last character (e.g., '1')

        inFile.ignore(); // skip empty line
    }

    int studentIDs[NUM_STUDENTS];
    char studentAnswers[NUM_STUDENTS][NUM_QUESTIONS];
    int scores[NUM_STUDENTS] = {0};
    int missedBy[NUM_QUESTIONS] = {0};

    for (int s = 0; s < NUM_STUDENTS; s++) {
        cout << "\nEnter Student ID " << s + 1 << ": ";
        cin >> studentIDs[s];
        cin.ignore();

        for (int q = 0; q < NUM_QUESTIONS; q++) {
            cout << "\nQ" << q + 1 << ": " << questions[q] << "\n";
            for (int c = 0; c < 4; c++) {
                cout << c + 1 << ") " << choices[q][c] << "\n";
            }

            cout << "Enter your answer (1-4): ";
            cin >> studentAnswers[s][q];
            cin.ignore();

            if (studentAnswers[s][q] == correctAnswers[q]) {
                scores[s]++;
            } else {
                missedBy[q]++;
            }
        }
    }

    // Display Results
    cout << "\n===== RESULT =====\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Student " << studentIDs[i] << ": " << scores[i] * 20 << "% (" << scores[i] << "/" << NUM_QUESTIONS << ")\n";
    }

    cout << "\nQuestions missed:\n";
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cout << "Q" << i + 1 << ": Missed by " << missedBy[i] << " student(s)\n";
    }
}

int main() {
    int choice;
    cout << "1. Create Quiz File\n2. Start Quiz\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        createQuestionAnswerFile();
    } else if (choice == 2) {
        startQuiz();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
