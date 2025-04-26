#include<iostream>
using namespace std;

int main() {
    int num_of_students;
    cout << "Number of students (in start): ";
    cin >> num_of_students;

    float* marks = new float[num_of_students];
    cout << "Enter student marks: " << endl;
    for (int i = 0; i < num_of_students; i++) {
        cin >> marks[i];
    }

    float average = 0;
    for (int i = 0; i < num_of_students; i++) {
        average += marks[i];
    }
    average /= num_of_students;
    cout << "Average marks: " << average << endl;

    float highest_marks = marks[0];
    float lowest_marks = marks[0];
    for (int i = 1; i < num_of_students; i++) {
        if (highest_marks < marks[i]) {
            highest_marks = marks[i];
        }
        if (lowest_marks > marks[i]) {
            lowest_marks = marks[i];
        }
    }
    cout << "Highest marks: " << highest_marks << endl;
    cout << "Lowest marks: " << lowest_marks << endl;

    cout << "Updated Marks: ";
    for (int i = 0; i < num_of_students; i++) {
        marks[i] += 2;
        cout << marks[i] << " ";
    }
    cout << endl;

    int new_size = num_of_students + 3;
    float* new_marks = new float[new_size];
    for (int i = 0; i < num_of_students; i++) {
        new_marks[i] = marks[i];
    }
    delete[] marks;

    cout << "Number of students (updated): " << new_size << endl;
    cout << "Enter student marks for 3 new students: " << endl;
    for (int i = num_of_students; i < new_size; i++) {
        cin >> new_marks[i];
    }

    average = 0;
    for (int i = 0; i < new_size; i++) {
        average += new_marks[i];
    }
    average /= new_size;
    cout << "Average marks: " << average << endl;

    highest_marks = new_marks[0];
    lowest_marks = new_marks[0];
    for (int i = 1; i < new_size; i++) {
        if (highest_marks < new_marks[i]) {
            highest_marks = new_marks[i];
        }
        if (lowest_marks > new_marks[i]) {
            lowest_marks = new_marks[i];
        }
    }
    cout << "Highest marks: " << highest_marks << endl;
    cout << "Lowest marks: " << lowest_marks << endl;

    cout << "Updated Marks: ";
    for (int i = 0; i < new_size; i++) {
        new_marks[i] += 2;
        cout << new_marks[i] << " ";
    }
    cout << endl;

    delete[] new_marks;
    return 0;
}