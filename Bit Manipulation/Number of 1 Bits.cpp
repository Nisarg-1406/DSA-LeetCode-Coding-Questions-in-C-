    int hammingWeight(uint32_t n) {
        int count=0;
        while (n) {
            // cout<<n<<"\n";
            count += n&1;
            n >>= 1; 
        }
        return count;
        
        - Using right most set bits (rsbm)
        int cnt = 0;
        while (n != 0) {
            int rsbm = n & -n;
            n = n - rsbm;
            cnt = cnt + 1;        
        }
        return cnt;
    }
