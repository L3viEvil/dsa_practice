#include <iostream>
#include <math.h>

using namespace std;

int n = 100;
int x = 3;
int arr[10001]; 
int sum[10001];
int count = 0;

int exp(int a, int b) {
    // code de quy can nho dieu kien neo
    if (b == 0) return 1;
    if(b % 2 == 0) {
        int x = exp(a, b/2);
        return x * x;
    }
    else {
        int x = exp(a, (b-1)/2);
        return a * x * x;
    }
}

void printArr(int i) {
    for (int j = 1; j <= i; j++) {
        cout << arr[j] << " ";
    }
    count += 1;
    cout << endl;
    return;
}

void Try(int i) {
    for (int j = arr[i-1]; j < n; j++) { // phan tu sau lon hon hoac bang phan tu truoc
        arr[i] = j;
        sum[i] = sum[i-1] + exp(j, x);
        if (sum[i] == n) {
            printArr(i);
        }
        else if (sum[i] < n) {
            Try(i+1);
        }
    }
    return;
}

int main() {
    arr[0] = 1;
    sum[0] = 0;
    Try(1); // Bat dau thu tu 1
    cout << "Number of ways are " << count << endl;
    return 0;
}