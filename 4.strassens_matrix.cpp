#include <iostream>
using namespace std;

int main() {
    int a[2][2], b[2][2], c[2][2], i, j;
    int m1, m2, m3, m4, m5, m6, m7;

    // Input elements for the first matrix
    cout << "Enter the 4 elements of the first matrix: " << endl;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            cin >> a[i][j];

    // Input elements for the second matrix
    cout << "Enter the 4 elements of the second matrix: " << endl;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            cin >> b[i][j];

    // Display the first matrix
    cout << "The first matrix:" << endl;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Display the second matrix
    cout << "The second matrix:" << endl;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    // Strassen algorithm steps for matrix multiplication
    m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    m2 = (a[1][0] + a[1][1]) * b[0][0];
    m3 = a[0][0] * (b[0][1] - b[1][1]);
    m4 = a[1][1] * (b[1][0] - b[0][0]);
    m5 = (a[0][0] + a[0][1]) * b[1][1];
    m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    // Calculate result matrix using Strassen algorithm
    c[0][0] = m1 + m4 - m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;

    // Display the result matrix
    cout << endl << "The Strassen matrix after multiplication is:" << endl;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


/*
Output :-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 4.strassens_matrix.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out
Enter the 4 elements of the first matrix: 
2 4
6 8
Enter the 4 elements of the second matrix: 
1 3
5 7
The first matrix:
2 4 
6 8 
The second matrix:
1 3 
5 7 

The Strassen matrix after multiplication is:
22 34 
46 74 
*/
