#include <iostream>
#include <algorithm>

using namespace std;
int arr[1001];
int inArr[1001];
long sum[1001];
int x;
int total = 0;

void printArray(int i) {
    cout << "++++++++" << endl;
    for (int j = 1; j <= i; j++) {
        cout << inArr[arr[j]] << " ";
    }
    cout << endl;
    cout << "++++++++" << endl;
    return;
}

void Try(int i, int n, int x) {
    for (int j = arr[i-1]; j < n; j++) {
        arr[i] = j;
        sum[i] = sum[i-1] + inArr[arr[i]];
        if (sum[i] == x) {
            printArray(i);
            total += 1;
        }
        else if (sum[i] < x) {
            Try(i+1, n, x);
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inArr[i];
    }
    cin >> x;
    sort(inArr, inArr+n);
    arr[0] = 0;
    sum[0] = 0;
    Try(1, n, x);

    return 0;
}