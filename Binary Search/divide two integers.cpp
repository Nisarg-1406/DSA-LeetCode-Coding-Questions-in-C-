    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend <0 ^ divisor <0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp = temp << 1;
                m = m << 1;
                cout<<temp<<" "<<m<<"\n";
            }
            dvd -= temp;
            cout<<"The dvd and temp is : "<<dvd<<" "<<temp<<"\n";
            ans += m;
            cout<<"The ans and m is : "<<ans<<" "<<m<<"\n";
        }
        return sign * ans;
    }
