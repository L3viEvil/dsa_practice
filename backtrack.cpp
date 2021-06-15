#include<iostream>
#include<math.h>
#include<string>

using namespace std;

// int Try(int n) {

// }

int square(int x) {
    return x * x;
}

int pow(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        int x = pow(a, b/2);
        return x * x;
    }
    else {
        int x = pow(a, (b-1)/2);
        return a * x * x;
    }
}

int main() {
    int a = 10, b = 5;
    cout << pow(a, b) << endl;

    return 0;
}