#include <iostream>

using namespace std;
int X[1001];
int bestWay[1001];
int checkTable[1001];
int N, m;
int cost[1001];
int dist[1001][1001];
long maxDist = 99999;
long minCost = maxDist;

void initCheckTable() {
    for (int i = 0; i <= N; i++) {
        checkTable[i] = true;
    }
}

void init() {
    cin >> N >> m;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = maxDist;
        }
    }
    int idx1, idx2;
    for (int i = 0; i < m; i++) {
        cin >> idx1 >> idx2;
        cin >> dist[idx1][idx2];
        dist[idx2][idx1] = dist[idx1][idx2];
    }
    initCheckTable();
}

void printResult() {
    for (int i = 1; i <= N; i++) {
        cout << bestWay[i] << " -> ";
    }
    cout << "1";
    cout << endl << minCost << endl;
}

void Try(int i) { // bien i trong try dai dien cho lan di den thanh pho thu may, lan 1 tai thanh pho 1
    for (int j = 2; j <= N; j++) {
        if (checkTable[j] == true && dist[X[i-1]][j] != maxDist) {
            X[i] = j;
            cost[i] = cost[i-1] + dist[X[i-1]][j];
            if (cost[i] < minCost) {
                if (i == N) {
                    if (cost[i] + dist[X[i]][1] < minCost) {
                        minCost = cost[i] + dist[X[i]][1];
                        for (int i = 1; i <= N; i++) {
                            bestWay[i] = X[i];
                        }
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
}


int main() {
    init();
    X[1] = 1;
    cost[1] = 0;
    Try(2);
    printResult();

    return 0;
}