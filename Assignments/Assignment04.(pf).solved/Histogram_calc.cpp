#include<iostream>
#include<fstream>
using namespace std;

const int BestCount = 4;

// functions used
void allocate_Array(float**& scored_marks, int rows, int cols);
void Deallocate_Array(float** scored_marks, int rows);
void store_marks(float** scored_marks, ifstream& read, int rows, int cols);
void sortMarks(float** scored_marks, ifstream& read, int rows, int cols);
void FindAverage(ifstream& read, float** scored_marks, int rows, int cols);
int countTotalElements(ifstream& read);
void countRowsAndCols(ifstream& read, int& rows, int& cols, int total_Elements);
void Display_output(float** scored_marks, float marks_average_for_student[50], ifstream& read, int rows, int cols);



// Allocating array to store marks: 
void allocate_Array(float**& scored_marks, int rows, int cols) {
    scored_marks = new float* [rows];
    for (int i = 0;i < rows;i++) {
        scored_marks[i] = new float[cols];
    }
}
// De-allocationg array: 
void Deallocate_Array(float** scored_marks, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[]scored_marks[i];
    }
    delete[] scored_marks;
}
// Function to round average for histogram: 
int round_average(float average) {
    int integer_part = (int)average;  // get integer part
    float decimal_part = average - integer_part;  // get decimal part  
    if (decimal_part >= 0.5) {
        return integer_part + 1;  // add 1 if multiplied is greater than 1
    }
    else {
        return integer_part;  // return unchanged integer part
    }
}
// Function to display average and histogram: 
void Display_output(float** scored_marks, float marks_average_for_student[50], ifstream& read, int rows, int cols) {
    read.clear();
    read.seekg(0, ios::beg);
    char firstLine[100];
    read.getline(firstLine, 100);
    for (int i = 0;i < rows;i++) {
        cout << " " << i + 1 << "   ";
        for (int j = cols - BestCount;j < cols;j++) {
            cout << scored_marks[i][j] << "  ";
        }
        cout << "  " << marks_average_for_student[i] << endl;
    }

    cout << endl << " Results: " << endl << endl;
    // Printing Histogram:
    for (int i = 0;i < rows;i++) {
        cout << " S" << i + 1 << " ";
        for (int j = 1;j <= round_average(marks_average_for_student[i]);j++) {
            cout << "*";
        }
        cout << endl;
    }
}
// Function to store marks from file to array: 
void store_marks(float** scored_marks, ifstream& read, int rows, int cols) {
    read.clear();
    read.seekg(0, ios::beg);
    char firstLine[100];
    read.getline(firstLine, 100); // skip 1st line
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            read >> scored_marks[i][j];
        }
    }
}
// Function to sort marks: 
void sortMarks(float** scored_marks, ifstream& read, int rows, int cols) {
    cout << endl;
    store_marks(scored_marks, read, rows, cols);
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            for (int k = j + 1; k < cols; k++) {
                if (scored_marks[i][j] > scored_marks[i][k]) {
                    float temp = scored_marks[i][j];
                    scored_marks[i][j] = scored_marks[i][k];
                    scored_marks[i][k] = temp;
                }
            }
        }
    }
}
// Function to calculate average:
void FindAverage(ifstream& read, float** scored_marks, int rows, int cols) {
    sortMarks(scored_marks, read, rows, cols);
    float* marks_average_for_student = new float[50]; // array to store students averages
    float sum;
    for (int i = 0;i < rows;i++) {
        sum = 0;
        for (int j = cols - BestCount;j < cols;j++) {
            sum += scored_marks[i][j]; // count sum
        }
        marks_average_for_student[i] = sum / BestCount;// calculate average
    }
    Display_output(scored_marks, marks_average_for_student, read, rows, cols);
    delete[]marks_average_for_student;
}
// function to count total elements:
int countTotalElements(ifstream& read) {
    read.clear();
    read.seekg(0, ios::beg);
    float element;
    int elements_Count = 0;
    char firstLine[100];
    read.getline(firstLine, 100);// skip 1st line
    while (read >> element) {
        elements_Count++;
    }
    return elements_Count;
}
// function to calculate rows and columns:
void countRowsAndCols(ifstream& read, int& rows, int& cols, int total_Elements) {
    read.clear();
    read.seekg(0, ios::beg);
    char* temp_line = new char[300];
    // Count rows: 
    while (read.getline(temp_line, 300)) {
        rows++;
    }
    rows = rows - 1;

    // Calculate columns:
    cols = total_Elements / rows;

    delete[]temp_line;
}

int main() {

    // For quizes:
    cout << "\n\n\t\t\t\t Result for Quizes:\n" << endl;
    cout << "S_ID ";
    for (int n = 1;n <= BestCount;n++) {
        cout << "Q" << n << " ";
    }
    cout << "Average" << endl;
    int rows = 0, cols = 0;
    ifstream read_Quizes("quizesMarks.txt");
    int total_Elements = countTotalElements(read_Quizes);
    countRowsAndCols(read_Quizes, rows, cols, total_Elements);
    float** scored_marks;
    allocate_Array(scored_marks, rows, cols);
    FindAverage(read_Quizes, scored_marks, rows, cols);
    Deallocate_Array(scored_marks, rows);
    read_Quizes.close();

    // For Assignments:
    cout << "\t\t\t\t Result for Assignments:\n" << endl;
    cout << "S_ID ";
    for (int n = 1;n <= BestCount;n++) {
        cout << "A" << n << " ";
    }
    cout << "Average" << endl;
    rows = 0, cols = 0;
    ifstream read_assignments("AssignmentsMarks.txt");
    total_Elements = countTotalElements(read_assignments);
    countRowsAndCols(read_assignments, rows, cols, total_Elements);
    allocate_Array(scored_marks, rows, cols);
    FindAverage(read_assignments, scored_marks, rows, cols);
    Deallocate_Array(scored_marks, rows);
    read_assignments.close();
    return 0;
}