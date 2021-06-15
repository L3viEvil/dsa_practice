#include <iostream>

using namespace std;

/*
Liet ke chinh hop chap k cua n. Trong bai nay, mot day quan tam den ca thu tu nen khong can xep theo mot quy tac.
Tu tuong, tai moi vi tri, chon tat ca cac gia tri tu 1 den n ma chua duoc giu boi so nao. Ta se dung them mot mang de ghi nho xem gia 
tri nao da duoc giu.
*/

int n = 15;
int k = 5;
int arr[5];
bool checkTable[15];
int count = 0;

void printArr() {
    for (int  i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    count += 1;
    cout << endl;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (checkTable[j]) {
            arr[i] = j;
            if (i == k-1) {
                printArr();
                return;
            }
            else {
                checkTable[j] = false;
                Try(i+1);
                checkTable[j] = true;
            }
        }
    }
}

int main() {
    for (int  i = 0; i < 15; i++) {
        checkTable[i] = true;
    }
    Try(0);
    cout << count << endl;

    return 0;
}