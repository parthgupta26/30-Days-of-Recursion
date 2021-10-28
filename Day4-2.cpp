#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void printEncodings(string str, string answerSoFar) {
    if(str.size() == 0) {
        cout << answerSoFar << endl;
        return;
    }
    else if(str.size() == 1) {
        char ch = str.at(0);
        if(ch == '0') {
            return;
        }
        else {
            int value = ch - '0';
            char currChar = 'a' + value - 1;
            cout << answerSoFar + currChar << endl;
        }
    }
    else {
        char ch = str.at(0);
        string remaining1 = str.substr(1);
        if(ch == '0') {
            return;
        }
        else {
            int value = ch - '0';
            char currChar = 'a' + value - 1;
            printEncodings(remaining1, answerSoFar + currChar);
        }
        string firstTwo = str.substr(0, 2);
        string remaining2 = str.substr(2);
        if(stoi(firstTwo) <= 26) {
            int value = stoi(firstTwo);
            char currChar = 'a' + value - 1;
            printEncodings(remaining2, answerSoFar + currChar);
        }
    }
}

int main(){
    string str;
    cin >> str;
    printEncodings(str, "");
    return 0;
}