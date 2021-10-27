#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> codes = {".;", "abc" ,"def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"}; 

vector<string> getKeyPadSequence(string str) {
    if(str.size() == 0) {
        return {""};
    }
    char firstNum = str.at(0);
    string remainingNums = str.substr(1);
    vector<string> res = getKeyPadSequence(remainingNums);
    vector<string> ans;
    for(string s : res) {
        string code = codes[firstNum - '0'];
        for(char ch : code) {
            ans.push_back(ch + s);
        }
    } 
    return ans;
}

int main(){
    string str;
    cin >> str;
    vector<string> ans = getKeyPadSequence(str);
    for(string s : ans) {
        cout << s << endl;
    }
    return 0;
}