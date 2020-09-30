    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string ans;
        if (numerator > 0 ^ denominator > 0) ans += '-';
        long n = labs(numerator), d = labs(denominator), r = n % d;
        ans += to_string(n / d);
        if (!r) return ans;
        ans += '.';
        unordered_map<long, int> rs;
        while (r) {
            if (rs.find(r) != rs.end()) {
                ans.insert(rs[r], "(");
                cout<<"rs[r] and ans : "<<rs[r]<<" "<<ans<<"\n";
                ans += ')';
                break;
            }
            rs[r] = ans.size();
            cout<<"The rs[r] is : "<<rs[r]<<"\n";
            r *= 10;
            cout<<"r : "<<r<<"\n";
            ans += to_string(r / d);
            cout<<"ans : "<<ans<<"\n";
            r %= d;
            cout<<"the r is : "<<r<<"\n";
        }
        return ans;
    }
