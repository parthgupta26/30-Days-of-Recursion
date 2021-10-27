#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> getStairPaths(int nums) {
    if(nums == 0) {
        return {""};
    }
    else if(nums < 0) {
        return {};
    }
    vector<string> path1 = getStairPaths(nums - 1);
    vector<string> path2 = getStairPaths(nums - 2);
    vector<string> path3 = getStairPaths(nums - 3);
    vector<string> paths;
    for(string path : path1) {
        paths.push_back("1" + path);
    }
    for(string path : path2) {
        paths.push_back("2" + path);
    }
    for(string path : path3) {
        paths.push_back("3" + path);
    }
    return paths;
}

int main(){
    int num;
    cin >> num;
    vector<string> ans = getStairPaths(num);
    for(string s : ans) {
        cout << s << endl;
    }
    return 0;
}