#include <iostream>

using namespace std;

int n = 15;
int k = 4;
bool checkArr[6];
int arr[6];
int count = 0;

void printArr() {
    for (int i = 1; i <= k; i++) {
        cout << arr[i] << " ";
    }
    count += 1;
    cout << endl;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if(checkArr[j]) {
            arr[i] = j;
            if (i == k) {
                printArr();
            }
            else {
                checkArr[j] = false; // ghi nho gia tri j da duoc chon
                Try(i+1);
                checkArr[j] = true; // bo ghi nho rang gia tri j da duoc chon
            }
        }
    }

}


int main() {

    for (int i = 0; i <= n; i++){
        checkArr[i] = true;
    }
    Try(1);
    cout << count << endl;

    return 0;
}