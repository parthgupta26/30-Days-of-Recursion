#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void printPermutationsTwo(int currBox, int totalBoxes, vector<bool> &usedItem, int selectionSoFar, int totalSelections, string answerSoFar) {
    if(currBox > totalBoxes) {
        if(selectionSoFar == totalSelections) {
            cout << answerSoFar << endl;
        }
        return;
    }
    for(int i = 0; i < totalSelections; i++) {
        if(usedItem[i] == false) {
            usedItem[i] = true;
            printPermutationsTwo(currBox + 1, totalBoxes, usedItem, selectionSoFar + 1, totalSelections, answerSoFar + to_string(i + 1));
            usedItem[i] = false;
        }
    }
    printPermutationsTwo(currBox + 1, totalBoxes, usedItem, selectionSoFar, totalSelections, answerSoFar + "0");
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<bool> usedItem(r, false);
    printPermutationsTwo(1, n, usedItem, 0, r, "");
    return 0;
}