// Writing reversed digit and its sum:
#include <iostream>
#include <fstream>
using namespace std;
int reverseDigit(int number);
void writeReversed(ofstream& write, int reversed);
int main()
{
    ifstream read("data.txt");
    ofstream write("Reversed.txt");
    int number;
    while (read >> number)
    {
        int reversedNumber = reverseDigit(number);
        writeReversed(write, reversedNumber);
    }
    read.close();
    write.close();
    return 0;
}
int reverseDigit(int number)
{
    int reversed = 0;
    int sum = 0;
    bool isNegative = false;
    if (number < 0)
    {
        isNegative = true;
        number = -number;    // Making num positive for processing:
    }
    while (number != 0)
    {
        int digit = number % 10;  // Taking the last digit of the number
        reversed = reversed * 10 + digit;
        sum += digit;
        number /= 10;   // Removing one last digit from the original num(for the loop ietration)
    }
    if (isNegative)
    {
        reversed = -reversed;   // Making negative as it was before processing
    }
    return reversed;
}
void writeReversed(ofstream& write, int reversed)
{
    write << reversed << " = ";
    int sum = 0;
    // Calculating sum of the reversed digit: :
    while (reversed != 0)
    {
        int digit = reversed % 10;
        sum += digit;
        reversed /= 10;
    }
    write << sum << endl;
}

