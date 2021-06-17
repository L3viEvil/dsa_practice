#include <iostream>

using namespace std;
int n = 8;
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===============" << endl;
    count += 1;
    return;
}

void Try(int i, int j, int numOfMove) {
    // if (numOfMove == n*n) {
    //     printTable();
    //     return;
    // }
    for (int index = 0; index <= 8; index++) {
        int new_i = i + xMove[index];
        int new_j = j + yMove[index];
        if (isSave(new_i, new_j) == true && checkTable[new_i][new_j] == true) {
            cout << numOfMove << " i " << new_i << " " << new_j << " " << isSave(new_i, new_j) << endl;
            arr[new_i][new_j] = numOfMove;
            numOfMove += 1;
            if (numOfMove == n*n) {
                printTable();
            }
            else {
                checkTable[new_i][new_j] = false; // danh dau la da tham 
                Try(new_i, new_j, numOfMove);
                checkTable[new_i][new_j] = true; // bo danh dau la da tham
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
    Try(0, 0, 0);
    cout << count << endl;

    return 0;
}