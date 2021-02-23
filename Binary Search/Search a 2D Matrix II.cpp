    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        int j = col - 1;
        while((i>=0 && i<row) && (j>=0 && j<col)){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j = j - 1;
            else if(matrix[i][j] < target) i = i + 1;
        }
        return false;
    }    
