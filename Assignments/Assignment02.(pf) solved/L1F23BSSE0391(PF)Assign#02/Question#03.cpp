// C++ program adds a “.” at the end of each line:
#include<iostream>
#include<fstream>
using namespace std;
int count_sentences(ifstream& file);
int main() {
    char filename[20] = { "Pakistan.txt" };
    ifstream read;
    char arr[100];
    read.open(filename);
    fstream write;
    write.open(filename);
    bool check = false;
    while (read.getline(arr, 100))// Reading from the file.
    {
        if (check)
        {
            write << endl;
        }
        write << arr << ".";
        check = true;
    }
    read.clear();
    read.close();
    write.close();
    ifstream modified_file(filename);
    int total_sentences = count_sentences(modified_file);
    cout << "Total sentences in the paragreaph: " << total_sentences << endl;

    return 0;
}
int count_sentences(ifstream& file)
{

    int sentence_count = 0;
    char dot;
    while (file >> dot)
    {
        if (dot == '.')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}