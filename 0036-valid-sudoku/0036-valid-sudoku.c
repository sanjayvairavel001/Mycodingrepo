#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};
    
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') continue;
            
            int val = board[r][c] - '1';
            int mask = 1 << val;
            int boxIdx = (r / 3) * 3 + (c / 3);
            
            if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIdx] & mask)) {
                return false;
            }
            
            rows[r] |= mask;
            cols[c] |= mask;
            boxes[boxIdx] |= mask;
        }
    }
    return true;
}