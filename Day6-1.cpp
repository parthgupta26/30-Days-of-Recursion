#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void displayPermutations(vector<int> &permutations) {
    for(int i = 0; i < permutations.size(); i++) {
        cout << permutations[i] << "";
    }
    cout << endl;
}

void printPermutations(vector<int> &permutations, int currItem, int totalItems) {
    if(currItem > totalItems) {
        displayPermutations(permutations);
        return;
    }
    for(int i = 0; i < permutations.size(); i++) {
        if(permutations[i] == 0) {
            permutations[i] = currItem;
            printPermutations(permutations, currItem + 1, totalItems);
            permutations[i] = 0;
        }
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> permutations(n, 0);
    printPermutations(permutations, 1, r);
    return 0;
}