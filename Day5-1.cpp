#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void floodFill(vector<vector<int>> &arr, int sr, int sc, string answerSoFar) {
    if(sr < 0 || sc < 0 || sr > arr.size() - 1 || sc > arr[0].size() - 1 || arr[sr][sc] == 1) {
        return;
    }
    if((sr == arr.size() - 1) && (sc == arr[0].size() - 1)) {
        cout << answerSoFar << endl;
        return;
    }
    arr[sr][sc] = 1;
    floodFill(arr, sr - 1, sc, answerSoFar + "t");
    floodFill(arr, sr, sc - 1, answerSoFar + "l");
    floodFill(arr, sr + 1, sc, answerSoFar + "d");
    floodFill(arr, sr, sc + 1, answerSoFar + "r");
    arr[sr][sc] = 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    floodFill(arr, 0, 0, "");
    return 0;
}