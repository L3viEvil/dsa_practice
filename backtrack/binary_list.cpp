#include<iostream>

using namespace std;

int n = 7;
int arr[100];

void printArr() {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return;
}

void initArr() {
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    return;
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        arr[i] = j;
        if (i == n-1) {
            printArr();
        }
        else {
            Try(i+1);
        }
    }

    return;
}

int main() {
    Try(0);

    return 0;
}