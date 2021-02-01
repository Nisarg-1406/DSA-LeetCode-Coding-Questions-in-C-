    int hammingWeight(uint32_t n) {
        int count=0;
        while (n) {
            // cout<<n<<"\n";
            count += n&1;
            n >>= 1; 
        }
        return count;
    }
