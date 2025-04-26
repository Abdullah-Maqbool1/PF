#include<iostream>
using namespace std;

int main() {
    int num_of_items;
    cout << "Number of items (in start): ";
    cin >> num_of_items;

    string* items = new string[num_of_items];
    cout << "Enter item names: " << endl;
    for (int i = 0; i < num_of_items; i++) {
        cin >> items[i];
    }

    cout << "Duplicates: ";
    for (int i = 0; i < num_of_items; i++) {
        for (int j = i + 1; j < num_of_items; j++) {
            if (items[i] == items[j]) {
                cout << items[i] << " ";
                break;
            }
        }
    }
    cout << endl;

    for (int i = 0; i < num_of_items; i++) {
        for (int j = i + 1; j < num_of_items; j++) {
            if (items[i] > items[j]) {
                string temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    cout << "Sorted items: ";
    for (int i = 0; i < num_of_items; i++) {
        cout << items[i] << " ";
    }
    cout << endl;

    int new_size = num_of_items - 2;
    string* new_items = new string[new_size];
    for (int i = 0; i < new_size; i++) {
        new_items[i] = items[i];
    }
    delete[] items;

    cout << "Number of items (updated): " << new_size << endl;
    cout << "Item names (updated): ";
    for (int i = 0; i < new_size; i++) {
        cout << new_items[i] << " ";
    }
    cout << endl;

    cout << "Duplicates: ";
    for (int i = 0; i < new_size; i++) {
        for (int j = i + 1; j < new_size; j++) {
            if (new_items[i] == new_items[j]) {
                cout << new_items[i] << " ";
                break;
            }
        }
    }
    cout << endl;

    for (int i = 0; i < new_size; i++) {
        for (int j = i + 1; j < new_size; j++) {
            if (new_items[i] > new_items[j]) {
                string temp = new_items[i];
                new_items[i] = new_items[j];
                new_items[j] = temp;
            }
        }
    }

    cout << "Sorted items: ";
    for (int i = 0; i < new_size; i++) {
        cout << new_items[i] << " ";
    }
    cout << endl;

    delete[] new_items;
    return 0;
}