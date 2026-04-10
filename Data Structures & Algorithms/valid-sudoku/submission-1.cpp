#include <vector>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // We use 9x9 boolean arrays to track digits 1-9 for each row, col, and box
        // rows[i][k] means: Does digit 'k+1' exist in row 'i'?
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                // Convert char '1'-'9' to index 0-8
                int num = board[r][c] - '1';
                int boxIdx = (r / 3) * 3 + (c / 3);

                // Check if the number already exists in current row, column, or box
                if (rows[r][num] || cols[c][num] || boxes[boxIdx][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIdx][num] = true;
            }
        }
        return true;
    }
};