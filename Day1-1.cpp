#include <iostream>

using namespace std;

void printIncreasingThenDecreasing(int n) {
    if(n < 1) {
        return;
    }
    cout << n << endl;
    printIncreasingThenDecreasing(n - 1);
    cout << n << endl;
}

int main() {
    int n;
    cin >> n;
    printIncreasingThenDecreasing(n);
    return 0;
}