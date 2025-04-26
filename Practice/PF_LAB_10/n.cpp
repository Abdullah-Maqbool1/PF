#include<iostream>
#include<fstream>
using namespace std;

void rowCol(ifstream& read, int& rows, int cols[])
{
    char line[100];
    int col = 0;
    while (read.getline(line, 100))
    {
        int len = 0;
        int i = 0;
        while (line[i] != '\0')
        {
            if (line[i] == ' ')
            {
                len++;
            }
            i++;
        }
        cols[rows] = len;
        rows++;
    }
}
void readFromFile(ifstream& read, float**& arr, int rows, int cols[])
{
    arr = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new float[cols[i]];
    }
    read.ignore();
    read.seekg(0);
    float temp = 0.00;

    while (read >> temp)
    {
        cout << temp << " ";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols[i]; j++)
            {
                if (temp != -99)
                {
                    arr[i][j] = temp;
                }
            }
        }
    }
    read.close();
}
void display(float** arr, int rows, int*& cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ifstream read("Data.txt");
    int rows = 0;
    int* cols = new int[rows];
    float** arr = NULL;
    rowCol(read, rows, cols);


    readFromFile(read, arr, rows, cols);
    display(arr, rows, cols);


    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] cols;

    read.close();
    return 0;
}