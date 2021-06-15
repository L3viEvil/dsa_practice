#include <iostream>

using namespace std;

int n = 15;
int k = 4;
int arr[10];
int count = 0;

void printArr() {
    for (int i = 1; i <= k; i++) {
        cout << arr[i] << " ";
    }
    count += 1;
    cout << endl;
}

void Try(int i) {
    for (int j = arr[i-1]+1; j <= n-k+i; j++) {
        arr[i] = j;
        if (i == k) {
            printArr();
        }
        else {
            Try(i+1);
        }
    }
}

int main() {
    arr[0] = 0;
    Try(1);
    cout << count << endl;

    return 0;
}