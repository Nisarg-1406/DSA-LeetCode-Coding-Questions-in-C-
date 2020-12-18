    int minFlips(int a, int b, int c) { 
      int mask=1;
      int count=0;
      int bit_a,bit_b,bit_c;
      while (a || b || c){
        bit_a = a&1;
        bit_b = b&1;
        bit_c = c&1;
        if ((bit_a | bit_b) != bit_c){
          if (bit_a & bit_b){
            count=count+2;
          }
          else{
            ++count;
          }
        }
        a = a>>1;
        b = b>>1;
        c = c>>1;
      }
      return count;
    }
