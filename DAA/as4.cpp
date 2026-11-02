#include <bits/stdc++.h>
using namespace std;

int n;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solve(vector<vector<int>>& board, int row, int fixedRow) {
    if (row == n) return true;

    if (row == fixedRow)
        return solve(board, row + 1, fixedRow);

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solve(board, row + 1, fixedRow)) return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int firstRow, firstCol;

    cout << "Enter number of queens: ";
    cin >> n;

    cout << "Enter position of first queen (row and column): ";
    cin >> firstRow >> firstCol;

    if (n <= 0 || firstRow < 1 || firstRow > n ||
        firstCol < 1 || firstCol > n) {
        cout << "Invalid input!";
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    firstRow--;
    firstCol--;

    board[firstRow][firstCol] = 1;

    if (solve(board, 0, firstRow)) {
        cout << "N-Queens Solution:\n";

        for (auto row : board) {
            for (int cell : row)
                cout << cell << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists for this first queen position.\n";
    }

    return 0;
}