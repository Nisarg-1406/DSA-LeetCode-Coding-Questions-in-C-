    bool isValid(string s) {
        //Method -1 
        stack<char> st;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '[') st.push(c);
            if(c == ')' || c == '}' || c == ']'){
                if(st.empty()) return false;
                else if(st.top() == '(' && c == ')') st.pop();
                else if(st.top() == '{' && c == '}') st.pop();
                else if(st.top() == '[' && c == ']') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
        
        //Method -2 - Smart method
        stack<char> st;
        for (char c : s) {
          if (c == '(') st.push(')');
          else if (c == '{') st.push('}');
          else if (c == '[') st.push(']');
          else if (st.empty() || (st.top() != c)) return false;
              else st.pop();
        }
        return st.empty();
    }
