#include <iostream>

using namespace std;
int n = 7;
int k = 5;
int arr[100];
int count = 0;

void printArr() {
    for(int i = 1; i <= k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    count += 1;
    return;
}

void Try(int i) {
    for(int j = arr[i-1]+1; j <= n-k+i; j++) {
        arr[i] = j;
        if (i == k) {
            printArr();
        }
        else {
            Try(i+1);
        }
    }

    return;
}

int main() {
    arr[0] = 0; //khoi tao gia tri arr[0] bang 0 de tien thuc hien tinh toan
    Try(1); //goi ham Try tu 1
    cout << "Number of combination is " << count << endl;

    return 0;
}