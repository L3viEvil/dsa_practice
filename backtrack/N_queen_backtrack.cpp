#include <iostream>

using namespace std;
int n = 5;
int checkTable[1001][1001];
int arr[1001]; // array luu gia tri cua cac cot chua quan hau
int count = 0;

void initCheckTable() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            checkTable[i][j] = true;
        }
    }
}

bool checkValid(int row1, int column1, int row2, int column2) {
    if (row1 - column1 == (row2-column2)) { // check nam tren duong cheo
        return false;
    }
    if (row1 == row2 || column1 == column2) { // check nam tren duong thang
        return false;
    }
    if (row1+column1 == row2+column2) return false; // check nam tren duong cheo
    return true;
}

bool checkValidAll(int i, int columnIndex) {
    // bien i la bien chi so hang hien tai, co the dung de suy ra duoc thong tin 
    // ve hang va cot da dien truoc duoc
    for(int j = 0 ; j < i; j++) {
        if(!checkValid(j, arr[j], i, columnIndex)) { // neu vi tri hien tai ma khong thoa man bat ky vi tri truoc do nao, return false
            return false;
        }
    }
    return true;
}

// void printTable() {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (j == arr[i]) {
//                 cout << "*"; // neu la hau thi in *
//             }
//             else {
//                 cout << "#";
//             }
//             // cout << " ";
//         }
//         cout << endl;
//     }
//     cout << "-------------" << endl;
//     count += 1;
//     return;
// }

void printTable() {
    for (int i = 0; i < n; i++) {
        cout << "{" << i << ";" << arr[i] << "}" << " ";
    }
    cout << endl;
    count += 1;
    return;
}

void Try(int i) {
    // cout << "Hang " << i << endl;
    for (int j = 0; j < n; j++) {
        // cout << "checkTable " << checkTable[i][j] << endl;
        // cout << "check valid all " << checkValidAll(i, j) << endl;
        // cout << "Hang " << i << " Cot " << j << endl;
        if(checkTable[i][j] && checkValidAll(i, j)) {
            arr[i] = j; // ghi nhan gia tri vi tri cot cua con hau o hang i la j
            if(i == n-1){
                printTable();
            }
            else {
                checkTable[i][j] = false;
                Try(i+1);
                checkTable[i][j] = true;
            }
        }
    }
}

int main() {
    initCheckTable();
    Try(0);
    cout << count << endl;
    return 0;
}