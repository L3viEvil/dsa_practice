#include<iostream>

using namespace std;

int n = 15;
int k = 4;
int arr[30];
int count = 1;

/*
Liet to hop chap k phan tu cua n, tu 1, ..., n
Giai bang backtrack vet can cac truong hop
Nhan xxet can co mot thu tu de tranh viet liet ke bi trung lap
Ta chon thu tu do la day (x1 < x2 <... < xk)
*/

/* 
Code nay dang sai sai, sao lai i == k+1 thi dung lai cho ra so luong dung, trong khi i bat dau tu 1
*/



void printArr() {
    for (int i = 1; i <= k; i++) {
        cout << arr[i] << " ";
    }
    cout << count;
    count += 1;
    cout << endl;
}

void Try(int i) {
    for(int j = arr[i-1]+1; j < n-k+i+1; j++) {
        arr[i] = j;
        if (i == k+1) {
            printArr();
            return;
        }
        Try(i+1);
    }
}

int main() {
    arr[0] = 0;
    Try(1);
    cout << count << endl;
    return 0;
}