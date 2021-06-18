#include <iostream>

using namespace std;
int checkTable[1001][1001]; // su dung them 1 bang luu gia tri tinh toan de han che loi goi de quy

// Ham tinh kCn biet 0Cn = nCn = n va kCn = (k-1)C(n-1) + kC(n-1)

int calCombination(int k, int N) {
    if (k == 0 || k == N) {
        return 1;
    }
    int val1, val2;
    if (checkTable[k-1][N-1] == 0) {
        val1 = calCombination(k-1, N-1);
    }
    else {
        val1 = checkTable[k-1][N-1];
    }
    if (checkTable[k][N-1] == 0) {
        val2 = calCombination(k, N-1);
    }
    else {
        val2 = checkTable[k][N-1];
    }
    return val1 + val2;
}

int DP_cal_combination(int k, int N) {
    int checkTable[N+1][N+1];
    for (int i = 0; i <= N; i++) { // khoi tao bang tinh toan
        for (int j = 0; j <= N; j++) {
            if (i == j || j == 0) {
                checkTable[i][j] = 1; // truong hop k = 0 va truong hop k = N
            }
            else {
                checkTable[i][j] = 0;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= k; j++) {
            checkTable[i][j] = checkTable[i-1][j-1] + checkTable[i-1][j];
        }
    }
    return checkTable[N][k];
}

int main() {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            checkTable[i][j] = 0;
        }
    }
    cout << calCombination(1, 10) << endl;
    cout << calCombination(9, 10) << endl;
    cout << calCombination(0, 10) << endl;
    cout << calCombination(5, 10) << endl;
    cout << DP_cal_combination(5, 10) << endl;
    return 0;
}