    int numPairsDivisibleBy60(vector<int>& time) {
        //The below solution is the brute force solution, and it passes 31/34 test cases.
        /*int n = time.size();
        int cnt = 0;
        for(int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (((time[i] + time[j]) % 60) == 0) cnt = cnt + 1;
            }
        }
        return cnt;*/
        
        //optimised solution using the hashmap 
        vector<int> c(60);
        int res = 0;
        for (int t : time) {
            res += c[(600 - t) % 60];
            //res += c[(60 - t % 60)% 60];
            //cout << res << " "<<"\n"; 
            c[t % 60] += 1;
        }
        return res;
    }

Explanation towards the problems - 
t % 60 gets the remainder from 0 to 59.
We count the occurrence of each remainders in a array/hashmap c.

we want to know that, for each t,
how many x satisfy (t + x) % 60 = 0.

The straight forward idea is to take x % 60 = 60 - t % 60,
which is valid for the most cases.
But if t % 60 = 0, x % 60 = 0 instead of 60.

One solution is to use x % 60 = (60 - t % 60) % 60,
the other idea is to use x % 60 = (600 - t) % 60.
