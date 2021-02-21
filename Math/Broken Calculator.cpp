    int brokenCalc(int x, int y) {
        // Iterative solution 
        int cnt = 0;
        while (y > x) {
            if(y % 2 == 0) y = y / 2;
            else y = y + 1;
            cnt++;
        }
        if (x >= y) return (x-y) + cnt;
        return cnt;
        
        //Recursive solution 
        return X >= Y ? X - Y : 1 + Y % 2 + brokenCalc(X, (Y + 1) / 2);
    }
