#include <iostream>

using namespace std;
int n = 6;
int arr[100];
int sum[100];
int count = 0;

void printArr(int i) {
    for (int j = 1; j <= i; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void Try(int i) {
    for (int j = arr[i-1]; j <= n; j++) { // lay order la phan tu sau lon hon hoac bang phan tu truoc do
        arr[i] = j;
        sum[i] = sum[i-1] + arr[i];
        if (sum[i] == n) { 
            count += 1;
            printArr(i);
        }
        else if (sum[i] < n) {
            Try(i+1);
        }
    }
}

int main() {
    sum[0] = 0; // khoi tao sum bat dau tu 0
    arr[0] = 1; // Khoi tao phan tu dau tien cua day la 1 de tien tinh toan
    Try(1); // bat dau thu tu 1
    cout << "Number of ways are " << count << endl;

    return 0;
}