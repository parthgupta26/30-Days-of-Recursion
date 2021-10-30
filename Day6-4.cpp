#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void displayCombination(vector<int> &boxes) {
    string comb = "";
    for(int i = 0; i < boxes.size(); i++) {
        if(boxes[i] > 0) {
            comb += "i";
        }
        else {
            comb += "-";
        }
    }
    cout << comb << endl;
}

void printCombinationTwo(vector<bool> &boxes, int currItem, int totalItems, int idx) {
    if(currItem > totalItems) {
        displayCombination(boxes);
        return;
    }
    for(int i = idx; i < boxes.size(); i++) {
        if(boxes[i] == false) {
            boxes[i] = true;
            printCombinationTwo(boxes, currItem + 1, totalItems, i + 1);
            boxes[i] = false;
        }
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<bool> boxes(n , false);
    printCombinationTwo(boxes, 1, r, 0);
    return 0;
}