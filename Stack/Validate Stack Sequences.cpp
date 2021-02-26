    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Method - 1
        stack<int> st;
        int i = 0;
        for(int x : pushed){
            st.push(x);
            while(st.size() && st.top() == popped[i]) {
                st.pop();
                i = i + 1;
            }
        }
        return st.size() == 0;
        
        // Method - 2
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i = 0, j = 0;
        for (int x : pushed) {
            pushed[i++] = x;
            while (i > 0 && pushed[i-1] == popped[j]){
                //cout<<i<<"\n";
                --i, ++j;
                //cout<<"i : "<<i<<"\n";
            }
        }
        return i == 0;
    }
