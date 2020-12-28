    //Using min heap - smallest number would be on the top of the heap
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
        while (K--) {
            int x = pq.top();
            pq.pop();
            pq.push(-x);
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
