#include <iostream>

using namespace std;
int count = 0;


void solve(int n, int x, int y) {
    if (n == 1) {
        cout << "Chuyen 1 coc tu cot " << x << " sang cot " << y << endl; 
        count += 1;
    }
    else {
        solve(n-1, x, 6-x-y); // chuyen n-1 coc tu cot x sang cot tam 6-x-y
        solve(1, x, y); // chuyen 1 coc to nhat tu cot x sang cot y
        solve(n-1, 6-x-y, y); // chuyen n-1 coc tu cot 6-x-y sang cot y
    }
}

int main() {
    solve(8, 1, 3);
    cout << count << endl;

    return 0;
}