#include <iostream>

using namespace std;
int n;
// int map[1001][1001];
int checkTable[1001][1001];
int paths[1001][1001];
int minPaths = 9999999;
// int row, col;
int xMove[4] = {-1, 1, 0, 0};
int yMove[4] = {0, 0, 1, -1};
int row = 12;
int col = 10;
int map[12][10] = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

bool inMap(int i, int j) {
    if (i >= 0 && j >= 0 && i < row && j < col) return true;
    return false;
}

void initCheckTable() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            checkTable[i][j] = 0;
            paths[i][j] = 0;
        }
    }
}


void initMap() {
    // cin >> row >> col;
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cin >> map[i][j];
    //     }
    // }

    int xM[4] = {-1, 1, 0, 0};
    int yM[4] = {0, 0 , 1, -1};
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j] == 0) {
                for (int idx = 0; idx < 4; idx++) {
                    if (inMap(i+xM[idx], j+yM[idx])) {
                        map[i+xM[idx]][j+yM[idx]] = -1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j] == -1) {
                map[i][j] = 0;
            }
        }
    }
    cout << "++++++++++" << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "++++++++++" << endl;

}


void Try(int i, int j, int currLenght) {
    if (j == col - 1) {
        if (currLenght < minPaths) {
            minPaths = currLenght;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    paths[i][j] = checkTable[i][j];
                }
            }
            // cout << "----------" << endl; // for debugging
            // for (int i = 0; i < row; i++) {
            //     for (int j = 0; j < col; j++) {
            //         cout << paths[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << "----------" << endl;

        }
    }
    else {
        if (currLenght < minPaths){
            checkTable[i][j] = 1;
            for (int idx1 = 0; idx1 < 4; idx1 += 1) {
                int new_i = i + xMove[idx1];
                int new_j = j + yMove[idx1];
                if (inMap(new_i, new_j) == true && checkTable[new_i][new_j] == 0 && map[new_i][new_j] == 1) { // kiem tra dieu kien an toan
                    Try(new_i, new_j, currLenght+1);
                }
            }
            checkTable[i][j] = 0;
        }
    }
}

int minPathLenght() {
    initMap();
    initCheckTable();
    int minPathLength = minPaths;
    for (int i = 0; i < row; i++) {
        if (map[i][0] == 1) {
            checkTable[i][0] = 1;
            Try(i, 0, 0);
            checkTable[i][0] = 0;
        }
        
        // if (minPathLength < minPaths) {
        //     minPathLength = minPaths;
        // }
    }
    return minPaths;
}



int main() {
    int minlength = minPathLenght();
    if (minlength == 9999999) cout << "No way" << endl;
    else cout << minlength << endl;
    cout << "+++++++++" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

// 12 10
// 1 1 1 1 1 1 1 1 1 1
// 1 0 1 1 1 1 1 1 1 1
// 1 1 1 0 1 1 1 1 1 1
// 1 1 1 1 0 1 1 1 1 1 
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 0 1 1 1 1
// 1 0 1 1 1 1 1 1 0 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 0 1 1 1 1 0 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 0 1 1 1 1 1 1