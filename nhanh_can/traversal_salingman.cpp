#include <iostream>

using namespace std;
int cost[1001][1001];
int X[1001];
int bestWay[1001];
bool checkTable[1001];
long costArr[1001];
long maxCost = 99999999;
long minResults = maxCost;
int N, m;

void printResult(int N) {
    if (minResults == maxCost) {
        cout << "No way" << endl;
        return;
    }
    for (int i = 1; i <= N; i++) {
        cout << bestWay[i] << " -> ";
    }
    cout << "1";
    cout << endl;
    cout << minResults << endl;
}

void Try(int i) {
    for (int j = 2; j <= N; j++) {
        if (checkTable[j]) {
            X[i] = j;
            costArr[i] = costArr[i-1] + cost[X[i-1]][j];
            if (costArr[i] < minResults) {
                if (i == N) {
                    if (costArr[N] + cost[X[N]][1] < minResults) {
                        for (int idx = 0; idx < N+1; idx++) {
                            bestWay[idx] = X[idx];
                        }
                        minResults = costArr[N] + cost[X[N]][1];
                    }
                }
                else {
                    checkTable[j] = false;
                    Try(i+1);
                    checkTable[j] = true;
                }
            }
        }
    }
    return;
}


int main() {
    cin >> N >> m;
    for (int i = 0; i <= N; i++) {
        checkTable[i] = true;
    }

    int idx1, idx2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) cost[i][j] = 0;
            else cost[i][j] = maxCost;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> idx1 >> idx2;
        cin >> cost[idx1][idx2];
        cost[idx2][idx1] = cost[idx1][idx2];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    
    X[1] = 1;
    costArr[1] = 0;
    Try(2);
    printResult(N); 
    // cout <<  minResults << endl;

    return 0;
}

// 4 6
// 1 2 3
// 1 3 2
// 1 4 1
// 2 3 1
// 2 4 2
// 3 4 4