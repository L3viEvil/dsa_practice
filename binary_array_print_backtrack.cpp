#include <iostream>


using namespace std;

int n = 10;
int arr[30];

void printArr() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        arr[i] = j;
        if  (i == n-1) {
            printArr();
            return;
        }
        Try(i+1);
    }
}

int main() {
    Try(0);
    
    return 0;
}