    int findKthPositive(vector<int>& arr, int k) {
        //Using Binary search - Efficient
        int l = 0, r = A.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            if (A[m] - 1 - m < k) l = m + 1;
            else r = m;
        }
        return l + k;
        
        //Using array manipulation - 
        for(int i = 1, j = 0; i < arr[arr.size()-1]; i++){
            if(arr[j] == i) j++;
            else k--;
            if(k == 0) return i;
        }
        return arr[arr.size() - 1] + k;
    }
