class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // We will check rows first
        for (int i = 0; i < board.size(); i++) {
            if (checkRow(board[i]) == false) return false;
            if (checkColumn(board, i) == false) return false;
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (checkSquare(board, j, i) == false) return false;
            }
        }
        return true;
    }
    bool checkSquare(vector<vector<char>> board, int x, int y ) {
        int squareNums[9] = {0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                squareNums[board[y+i][x+j]-'1']++;
            }
        }
        for (int i: squareNums) if (i > 1) return false;
        return true;
    }
    bool checkRow(vector<char> row) {
        int rowNums[9] = {0};
        for (char ch: row) {
            if (ch == '.') continue;
            rowNums[ch-'1']++;
        }
        for (int i: rowNums) if (i > 1) return false;
        return true;
    }
    bool checkColumn(vector<vector<char>> board, int column) {
        int colNums[9] = {0};
        for (int i = 0; i < board.size(); i++) {
            colNums[board[i][column]-'1']++;
        }
        for (int i: colNums) if (i > 1) return false;
        return true;
    }
};
