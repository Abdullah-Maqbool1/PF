//remove identical characters from name: 
#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream read("Input.txt");
    ofstream write("Output.txt");

    int name_len;
    char* name;

    while (read >> name_len) {
        name = new char[name_len + 1];
        read.ignore();
        read.getline(name, name_len + 1);

        char* modified_name = new char[name_len + 1];
        int index = 0;

        for (int i = 0; i < name_len; i++) {
            bool same = false;
            for (int j = 1; j < name_len; j++) {
                if (isupper(name[i])) {
                    name[i] = tolower(name[i]);
                }
                if (i != j) {
                    if (name[i] == name[j]) {
                        same = true;
                        break;
                    }
                }
            }
            if (same == false) {
                modified_name[index] = name[i];
                index++;
            }
        }

        for (int k = 0; k < index; k++) {
            write << modified_name[k];
        }
        write << endl;

        delete[] name;
        delete[] modified_name;
    }

    read.close();
    write.close();

    return 0;
}
