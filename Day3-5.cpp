#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> getMazePathsWithJumps(int sr, int sc, int dr, int dc) {
    if(sr == dr && sc == dc) {
        return {""};
    }
    vector<string> paths;
    for(int h = 1; h < dc - sc + 1; h++) {
        vector<string> hpaths = getMazePathsWithJumps(sr, sc + h, dr, dc);
        for(string path : hpaths) {
            paths.push_back("h" + to_string(h) + path);
        }
    }
    for(int v = 1; v < dr - sr + 1; v++) {
        vector<string> vpaths = getMazePathsWithJumps(sr + v, sc, dr, dc);
        for(string path : vpaths) {
            paths.push_back("v" + to_string(v) + path);
        }
    }
    for(int d = 1; d < dc - sc + 1 && d < dr - sr + 1; d++) {
        vector<string> dpaths = getMazePathsWithJumps(sr + d, sc + d, dr, dc);
        for(string path : dpaths) {
            paths.push_back("d" + to_string(d) + path);
        }
    }
    return paths;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> ans = getMazePathsWithJumps(0, 0, n - 1, m - 1);
    for(string s : ans) {
        cout << s << endl;
    }
    return 0;
}