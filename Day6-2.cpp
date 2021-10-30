#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void printCombination(int currBox, int totalBoxes, int selectionSoFar, int totalSelections, string answerSoFar) {
    if(currBox > totalBoxes) {
        if(selectionSoFar == totalSelections) {
            cout << answerSoFar << endl;
        }
        return;
    }
    printCombination(currBox + 1, totalBoxes, selectionSoFar, totalSelections, answerSoFar + "-");
    printCombination(currBox + 1, totalBoxes, selectionSoFar + 1, totalSelections, answerSoFar + "i");
}

int main() {
    int n, r;
    cin >> n >> r;
    printCombination(1, n, 0, r, "");
    return 0;
}