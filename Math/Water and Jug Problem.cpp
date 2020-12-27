    
    //To find GCD and to use Bezout's identity which states - We can always find a and b to satisfy ax + bx = d where d = gcd(x, y).
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == z || y == z || x + y == z) return true;
        return z % gcd(x,y) == 0;
    }
    int gcd (int a, int b){
        while(b != 0 ){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
