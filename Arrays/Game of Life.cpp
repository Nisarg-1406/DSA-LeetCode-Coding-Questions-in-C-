    //Question link - https://leetcode.com/problems/game-of-life/
    //Condition checking - 
    bool isValid (vector<vector<int>>& board, int x, int y) {
        return (x >= 0 && y >= 0 && x < board.size() && y < board[0].size());
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        //x and y coordinates
        vector<int> ways_x = {1,-1,0,0,1,-1,1,-1}; 
        vector<int> ways_y = {0,0,1,-1,1,1,-1,-1};
        
        //traversing the matrix - 
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                int cnt = 0;
                
                for (int i = 0; i < 8; i++) {
                    int curr_x = ways_x[i] + row; //curr_x
                    int curr_y = ways_y[i] + col; //curr_y
                    if (isValid(board,curr_x,curr_y) && abs(board[curr_x][curr_y]) == 1) cnt = cnt + 1; //Counting of the number of 1s. 
                }
                if (board[row][col] == 1 && (cnt < 2 || cnt > 3)) board[row][col] = -1; //checking the first and the thrid condition 
                if (board[row][col] == 0 && cnt == 3) board[row][col] = 2; // Checking the 2nd and the 4th condition 
            }
        }
        //Finally adujsting out the matrix 
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] >= 1) board[row][col] = 1;
                else board[row][col] = 0;
            }
        }
    }   
