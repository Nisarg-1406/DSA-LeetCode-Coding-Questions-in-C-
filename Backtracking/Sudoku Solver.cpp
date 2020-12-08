    //This solution uses backtracking - 
    bool isValid (vector<vector<char>>& board, int row, int col, int c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false; // For rows
            if (board[row][i] == c) return false; // For cols
        }
        //this is for the 3*3 matrix - there are total of 9 matrix in 9*9 matrix
        int x0 = (row / 3) * 3, y0 = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[x0 + i][y0 + j] == c) return false;
            }
        }
        return true;
    }
    
    bool solve (vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return solve (board, row + 1, 0);
        if (board[row][col] != '.') return solve (board, row, col + 1);
        for (char c = '1'; c <= '9'; c++) {
            if (isValid (board, row, col, c)) {
                board[row][col] = c;
                if (solve (board, row, col + 1)) return true;
                board[row][col] = '.'; // bactracking 
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        solve (board, 0, 0);
    }
