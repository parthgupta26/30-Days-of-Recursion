#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isSafePlaceForQueen(vector<vector<int>> &chessBoard, int row, int col) {
    // checking for row
    for(int i = row - 1, j = col; i >= 0; i--) {
        if(chessBoard[i][j] == 1) {
            return false;
        }
    }
    // checking for left diagnol
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(chessBoard[i][j] == 1) {
            return false;
        }
    }
    // checking for right diagnol
    for(int i = row - 1, j = col + 1; i >= 0 && j < chessBoard.size(); i--, j++) {
        if(chessBoard[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void printNQueens(vector<vector<int>> &chessBoard, string queenSoFar, int row) {
    if(row == chessBoard.size()) {
        cout << queenSoFar << endl;
        return;
    }
    for(int col = 0; col < chessBoard.size(); col++) {
        if(isSafePlaceForQueen(chessBoard, row, col) == true) {
            chessBoard[row][col] = 1;
            printNQueens(chessBoard, queenSoFar + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            chessBoard[row][col] = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> chessBoard(n, vector<int> (n, 0));
    printNQueens(chessBoard, "", 0);
    return 0;
}