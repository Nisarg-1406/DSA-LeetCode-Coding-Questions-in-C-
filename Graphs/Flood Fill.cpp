    //It is DFS problem. 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            dfs (image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }
    void dfs (vector<vector<int>> &image, int sr, int sc, int color, int newColor) {
        
        //We cannot write image[sr][sc] != color as the first term because if (sr,sc) is out of box, then the constraints (sr,sc) will go in the image[sr][sc] and that would give runtime error as it OutOfBoundIndex. 
        //if (image[sr][sc] != color || sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return;
        
        if (sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size() || image[sr][sc] != color) return;
        image[sr][sc] = newColor;
        //Travel in all 4 directions. 
        dfs (image, sr + 1, sc, color, newColor);
        dfs (image, sr, sc + 1, color, newColor);
        dfs (image, sr - 1, sc, color, newColor);
        dfs (image, sr, sc - 1, color, newColor);
        
        //image[sr][sc] = color; //If we write this then will again get back the input ....so no backtracking.
    }
