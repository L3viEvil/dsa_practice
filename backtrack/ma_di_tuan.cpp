#include <iostream>
/*
Code nay va code tham khao cua Geekforgeeks deu dem ket qua n = 6 ra 304:/ 
bug truoc day cua code nay la cong truc tiep bien numOfMove trong for, dang ra la truyen vao thoi
Bai nay van de nham lan cho ket thuc vi minh dem cac truong hop van hay sai vl
*/

using namespace std;
int n = 5;
int arr[1001][1001];
bool checkTable[1001][1001];
int count = 0;
int xMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int yMove[8] = {2, 1, -1, -2, 2, 1, -1, -2};

bool isSave(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < n) {
        return true;
    }
    else {
        return false;
    }
}

void printTable() {
    cout << "===============" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===============" << endl;
    return;
}

void printCheckTable() {
    cout << "+++++++++++" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << checkTable[i][j] << " ";
        }
        cout << endl;
    }
    cout << "+++++++++++" << endl;
    return;
}

void Try(int i, int j, int numOfMove) {
    // cout << "i " << i << " " << j << " " << numOfMove << endl;
    // arr[i][j] = numOfMove; // danh dau duong tren bang
    // printTable();
    // printCheckTable();
    if (numOfMove == n*n) { // kiem tra dieu kien dung
        printTable();
        count += 1;
        return;
    }
    else if (numOfMove < n*n) {
        for (int index = 0; index <= 8; index++) {
            int new_i = i + xMove[index];
            int new_j = j + yMove[index];
            if (isSave(new_i, new_j) == true && checkTable[new_i][new_j] == true) {
                arr[new_i][new_j] = numOfMove;
                checkTable[new_i][new_j] = false; // danh dau da tham
                Try(new_i, new_j, numOfMove+1);
                checkTable[new_i][new_j] = true; //bo danh dau
            }
        }
    }
    return;
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            checkTable[i][j] = true; // ban dau chua bi ma di vao
        }
    }
    checkTable[0][0] = false;
    arr[0][0] = 0;
    Try(0, 0, 1);
    cout << count << endl;

    return 0;
}




// // C++ program for Knight Tour problem
// #include <bits/stdc++.h>
// using namespace std;
 
// #define N 5
// int countTotal = 0;
 
// void solveKTUtil(int x, int y, int movei, int sol[N][N],
//                 int xMove[], int yMove[]);

// int isSafe(int x, int y, int sol[N][N])
// {
//     return (x >= 0 && x < N && y >= 0 && y < N
//             && sol[x][y] == -1);
// }
 
// void printSolution(int sol[N][N])
// {
//     for (int x = 0; x < N; x++) {
//         for (int y = 0; y < N; y++)
//             cout << " " << setw(2) << sol[x][y] << " ";
//         cout << endl;
//     }
// }
 
// int solveKT()
// {
//     int sol[N][N];
 
//     /* Initialization of solution matrix */
//     for (int x = 0; x < N; x++)
//         for (int y = 0; y < N; y++)
//             sol[x][y] = -1;
 
//     /* xMove[] and yMove[] define next move of Knight.
//     xMove[] is for next value of x coordinate
//     yMove[] is for next value of y coordinate */
//     int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
//     int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
//     // Since the Knight is initially at the first block
//     sol[0][0] = 0;
 
//     /* Start from 0,0 and explore all tours using
//     solveKTUtil() */
//     // if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
//     //     cout << "Solution does not exist";
//     //     return 0;
//     // }
//     // else
//     //     printSolution(sol);
//     solveKTUtil(0, 0, 1, sol, xMove, yMove);
//     cout << countTotal << endl;
 
//     return 1;
// }
 
// /* A recursive utility function to solve Knight Tour
// problem */
// void solveKTUtil(int x, int y, int movei, int sol[N][N],
//                 int xMove[N], int yMove[N])
// {
//     int k, next_x, next_y;
//     if (movei == N * N) {
//         countTotal += 1;
//         printSolution(sol);
//     }
 
//     /* Try all next moves from
//     the current coordinate x, y */
//     for (k = 0; k < 8; k++) {
//         next_x = x + xMove[k];
//         next_y = y + yMove[k];
//         if (isSafe(next_x, next_y, sol)) {
//             sol[next_x][next_y] = movei;
//             solveKTUtil(next_x, next_y, movei + 1, sol,xMove, yMove);
//             sol[next_x][next_y] = -1;
//         }
//     }
// }
 
// // Driver Code
// int main()
// {
//       // Function Call
//     solveKT();
//     return 0;
// }
 
// // This code is contributed by ShubhamCoder