#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inArr[1001];
bool checkTable[1001];
int count;
int k;
int n;
vector<vector<int>> res;

void printResults() {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
} 

void Try(int count, vector<int> curr, int currSum, int sum) {
    for (int i = 0; i < n; i++) {
        if (checkTable[i]) {
            count += 1;
            if (count == n) {
                curr.push_back(inArr[i]);
                res.push_back(curr);
                printResults();
            }
            else {
                if (currSum += inArr[i] == sum) {
                    curr.push_back(inArr[i]);
                    checkTable[i] = false;
                    res.push_back(curr);
                    // Try(count+1,  )
                }
            }
            
        }
    }
}

int main() {

    return 0;
}