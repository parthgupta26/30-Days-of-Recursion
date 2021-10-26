#include <iostream>

using namespace std;

// Logic 1

int xRaiseToPowerN(int x, int n) {
    if(n == 0) {
      return 1;  
    } 
    return x * xRaiseToPowerN(x, n - 1);
}

// Logic 2
// It is better that logic one since number of calls has been decreased to logn from n;

int xRaiseToPowerN(int x, int n) {
    if(n == 0) {
      return 1;  
    } 
    int halfSquare = xRaiseToPowerN(x, n / 2);
    int res = halfSquare * halfSquare;
    if(n % 2 != 0) {
        res = res * x;
    }
    return res;
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << xRaiseToPowerN(x, n);
    return 0;
}