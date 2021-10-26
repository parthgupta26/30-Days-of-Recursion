#include <iostream>

using namespace std;

void printZigZagPattern(int n) {
    if(n < 1) {
      return;  
    } 
    cout << n << " ";
    printZigZagPattern(n - 1);
    cout << n << " ";
    printZigZagPattern(n - 1);
    cout << n << " ";
}

int main() {
    int n;
    cin >> n;
    printZigZagPattern(n);
    return 0;
}