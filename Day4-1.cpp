#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void printPermutations(string str, string answerSoFar) {
    if(str.size() == 0) {
        cout << answerSoFar << endl;
        return;
    }
    for(int i = 0; i < str.size(); i++) {
        char ch = str.at(i);
        string left = str.substr(0, i);
        string right = str.substr(i + 1);
        printPermutations(left + right, answerSoFar + ch);
    }
}

int main(){
    string str;
    cin >> str;
    printPermutations(str, "");
    return 0;
}