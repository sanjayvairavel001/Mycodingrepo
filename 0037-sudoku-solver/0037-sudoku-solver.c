#include <stdbool.h>

bool isValid(char** board, int row, int col, char val) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) return false;
        if (board[i][col] == val) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
    }
    return true;
}

bool solve(char** board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char val = '1'; val <= '9'; val++) {
                    if (isValid(board, r, c, val)) {
                        board[r][c] = val;
                        
                        if (solve(board)) return true;
                        
                        board[r][c] = '.'; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}