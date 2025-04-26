#include<iostream>
using namespace std;
int main()
{
    int i, j, m, n, p, q;
    int A[10][10], B[10][10], C[10];
    cout << "Enter number of rows and columns of matrix A : ";
    cin >> m >> n;
    cout << "Enter number of rows and columns of matrix B : ";
    cin >> p >> q;
    if ((m != p) && (n != q))
    {
        cout << "Dot product cannot be found as matrices are not of same size!";
        return 0;
    }
    cout << "Enter elements of matrix A : ";
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> A[i][j];
    cout << "Enter elements of matrix B : ";
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> B[i][j];
    for (i = 0; i < m; i++)
    {
        C[i] = 0;
        for (j = 0; j < n; j++)
            C[i] += A[i][j] * B[i][j];

    }
    cout << "Matrix A : \n ";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << "\n ";
    }
    cout << "Matrix B : \n ";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << B[i][j] << " ";
        cout << "\n ";
    }
    cout << "Dot product : \n ";
    for (i = 0; i < m; i++)
        cout << C[i] << " ";
    return 0;
}