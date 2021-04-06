    int minOperations(int n) {
        if(n % 2 == 1){ // Odd Case
            int N = (n - 1) / 2;  // number of elements before mid element
            return N * (N + 1); 
        }
        int N = n / 2;  // number of elements before mean of mid elements
        return N * N; 
    }
