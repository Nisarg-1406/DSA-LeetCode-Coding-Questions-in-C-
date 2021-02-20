    // 3 Approaches 
    // Method - 1
    int romanToInt(string s) {
        int cnt=0;
        map<char,int> mp;
        mp.insert(pair<char,int> ('I',1));
        mp.insert(pair<char,int> ('V',5));
        mp.insert(pair<char,int> ('X',10));
        mp.insert(pair<char,int> ('L',50));
        mp.insert(pair<char,int> ('C',100));
        mp.insert(pair<char,int> ('D',500));
        mp.insert(pair<char,int> ('M',1000));
        
        for(auto i=mp.begin(); i!=mp.end(); i++){
            if(i->first=="I" || i->first=="V" || i->first=="X" || i->first=="L" || i->first=="C" || i->first=="D" || i->first=="M"){
                if(i->second < (i+1)->second) cnt = cnt + ((i+1)->second - i->second);
                else cnt = cnt + i->second;
            }
        }
        return cnt;
    }
    
    // Method - 2
    int romanToInt(string s) {    
        int cnt=0;
        unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        
        for (int i = 0; i < s.length(); i++){
            if (T[s[i]] < T[s[i + 1]]){
                cout<<cnt<<" "<<s[i+1]<<" "<<s[i]<<" "<<T[s[i + 1]]<<" "<<T[s[i]]<<"\n";
                cnt = cnt + (T[s[i + 1]] - T[s[i]]); i++;
                
            }
            else{
                cnt = cnt + T[s[i]];
                cout<<"The count is : "<<cnt<<" "<<s[i]<<" "<<T[s[i]]<<"\n";
            }
        }
        return cnt;
    }    
    
    // Method - 3
    int h(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return -1;
    }
    int romanToInt(string s) {
        int l = s.size();
        int i=0,cnt=0;
        while(i<l){
            if(h(s[i])<h(s[i+1])){
                cnt = cnt + h(s[i+1]) - h(s[i]);
                i = i+2;
            }
            else{
                cnt = cnt + h(s[i]);
                i++;
            }
        }
        return cnt;
    }
