    uint32_t reverseBits(uint32_t n) {
        /*int result = 0;
        for(int i=0;i<32;i++){
            result = result << 1; //doing left shift in the result 
            if(n&1) result = result + 1;
            n = n >> 1; //doing right shift
        }
        return result;*/
        
        //n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
