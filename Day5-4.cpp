#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void displayChessBoard(vector<vector<int>> &chessBoard, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << chessBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightsTour(vector<vector<int>> &chessBoard, int n, int row, int col, int upcomingMove) {
    if(row < 0 || col < 0 || row > n - 1 || col > n - 1 || chessBoard[row][col] > 0) {
        return;
    }
    if(upcomingMove == n * n) {
        chessBoard[row][col] = upcomingMove;
        displayChessBoard(chessBoard, n);
        chessBoard[row][col] = 0;
        return;
    }
    chessBoard[row][col] = upcomingMove;
    printKnightsTour(chessBoard, n, row - 2, col + 1, upcomingMove + 1);
    printKnightsTour(chessBoard, n, row - 1, col + 2, upcomingMove + 1);
    printKnightsTour(chessBoard, n, row + 1, col + 2, upcomingMove + 1);
    printKnightsTour(chessBoard, n, row + 2, col + 1, upcomingMove + 1);
    printKnightsTour(chessBoard, n, row + 2, col - 1, upcomingMove + 1);
    printKnightsTour(chessBoard, n, row + 1, col - 2, upcomingMove + 1);
    printKnightsTour(chessBoard, n, row - 1, col - 2, upcomingMove + 1);
    printKnightsTour(chessBoard, n, row - 2, col - 1, upcomingMove + 1);
    chessBoard[row][col] = 0;
}

int main(){
    int n, row, col;
    cin >> n >> row >> col;
    vector<vector<int>> chessBoard(n, vector<int> (n, 0));
    printKnightsTour(chessBoard, n, row, col, 1);
    return 0;
}