// QUESTION 02:
#include<iostream>
#include<fstream>
#define size 7
using namespace std;
int main() {
    int record_num[size], oil_num[size], vehicle_num[size];
    double price[size];
    int day_arr[size], month_arr[size], year_arr[size];
    int day, month, year;

    // Taking input of date:
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    cout << "Date: " << day << "/" << month << "/" << year << endl;
    char slash[size];

    // Reading from file:
    ifstream read("makkiOil.txt");
    
    while (!read.eof()) {
        int i=0;
        read >> record_num[i] >> oil_num[i] >> vehicle_num[i] >> price[i] >> day_arr[i] >> slash[i] >> month_arr[i] >> slash[i] >> year_arr[i];
        if (day == day_arr[i] && month == month_arr[i] && year == year_arr[i]) {
            cout<<"Total Records: 6"<<endl;
            // Printing oil price and number:
            cout << " Oil Price: " << price[i] << endl;
            cout << " Oil number: " << oil_num[i] << endl;
            break;
        }
        i++;
    }
    read.close();
    return 0;
}
