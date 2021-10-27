#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr < 0 || sc < 0 || sr > dr || sc > dc) {
        return {};
    }
    if(sr == dr && sc == dc) {
        return {""};
    }
    vector<string> path1 = getMazePaths(sr, sc + 1, dr, dc);
    vector<string> path2 = getMazePaths(sr + 1, sc, dr, dc);
    vector<string> paths;
    for(string path : path1) {
        paths.push_back("h" + path);
    }
    for(string path : path2) {
        paths.push_back("v" + path);
    }
    return paths;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> ans = getMazePaths(0, 0, n - 1, m - 1);
    for(string s : ans) {
        cout << s << endl;
    }
    return 0;
}