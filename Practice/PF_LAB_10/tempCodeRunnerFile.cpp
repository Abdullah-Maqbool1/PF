#include <iostream>

void rotateMatrix(int arr[][4], int n) {
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            arr[i][j] = arr[j][i];
        }
    }
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[4 - i][4 - j];
            arr[4 - i][4 - j] = temp;
        }
    }
}

void printMatrix(int arr[][4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 4;
    int arr[][4] = { {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16} };

    std::cout << "Original Matrix: \n";
    printMatrix(arr, n);

    rotateMatrix(arr, n);

    std::cout << "\nRotated Matrix: \n";
    printMatrix(arr, n);

    return 0;
}
