#include <iostream>

using namespace std;
int cost[1001][1001];
int X[1001];
int bestWay[1001];
bool checkTable[1001];
long costArr[1001];
long maxCost = 99999999;
int N, m;

void printResult(int N) {
    if (maxCost == 99999999) {
        cout << "No way" << endl;
        return;
    }
    for (int i = 1; i <= N+1; i++) {
        cout << bestWay[i] << " -> ";
    }
    cout << endl;
    cout << maxCost << endl;
}

void Try(int i) {
    for (int j = 2; j <= N; j++) {
        if (checkTable[j] && cost[X[i-1]][j] < maxCost) {
            X[i] = j;
            costArr[i] = costArr[i-1] + cost[X[i-1]][j];
            if (costArr[i] < maxCost) {
                if (i == N) {
                    if (costArr[N] + cost[X[N]][1] < maxCost) {
                        for (int idx = 0; idx < N+1; idx++) {
                            bestWay[idx] = X[idx];
                        }
                        maxCost = costArr[N] + cost[X[N]][1];
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
    int idx1, idx2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cost[i][j] = maxCost;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> idx1 >> idx2;
        cin >> cost[idx1][idx2];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    
    X[1] = 0;
    costArr[1] = 0;
    Try(2);

    return 0;
}