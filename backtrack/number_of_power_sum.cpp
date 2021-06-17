#include <iostream>
#include <math.h>

using namespace std;
int n = 100;
int arr[1000]; // mang luu gia tri cac phan tu
int sum[1000]; // mang tinh tong gia tri cac phan tu
int count = 0;

void printArr(int i) {
    for (int j = 1; j <= i; j++) {
        cout << arr[j] << " ";
    }
    count += 1;
    cout << endl;
    return;
}

void Try(int i) {
    for (int j = arr[i-1]; j <= sqrt(n); j++) {
        arr[i] = j;
        sum[i] = sum[i-1] + pow(arr[i], 2);
        if (sum[i] == n) {
            printArr(i);
        }
        else if(sum[i] < n) {
            Try(i+1);
        }
    }
    return;
}


int main() {
    // init gia tri ban dau cho arr[0] va sum[0] de tien tinh toan
    arr[0] = 1;
    sum[0] = 0;
    Try(1); // thu bat dau tu gia tri i = 1
    cout << "Number of ways are " << count << endl;

    return 0;
}