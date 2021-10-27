#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> getSubSequence(string str) {
    if(str.size() == 0) {
        return {""};
    }
    char firstChar = str.at(0);
    string remaining = str.substr(1);
    vector<string> res = getSubSequence(remaining);
    vector<string> ans;
    for(string s : res) {
        ans.push_back("" + s);
        ans.push_back(firstChar + s);
    }
    return ans;
}

int main(){
    string str;
    cin >> str;
    vector<string> ans = getSubSequence(str);
    for(string s : ans) {
        cout << s << endl;
    }
    return 0;
}