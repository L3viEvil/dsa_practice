#include <iostream>

using namespace std;

int n = 7;
int k = 5;
int arr[100];
int checkTable[100];
int count = 0; // dem so luong hoan vi, dung de debug xem code dung chua

void printArr() {
    for(int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    count += 1;

    return;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (checkTable[j]) { // neu gia tri j van chua duoc su dung
            arr[i] = j;
            if (i == k-1) {
                printArr();
            }
            else {
                checkTable[j] = false; // danh dau la ghi nhan gan gia tri cua arr[i] la j
                Try(i+1);
                checkTable[j] = true; // luc thu xong i+1, truoc khi quay lui lai dang truoc thi bo danh dau
            }
        }
    }
}

int main() {
    for(int i = 0; i <= n; i++) {
        checkTable[i] = true;
    }
    Try(0);
    cout << "Number of partial permutation is " << count << endl;

    return 0;
}