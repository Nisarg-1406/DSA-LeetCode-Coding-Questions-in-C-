    string toLowerCase(string s) {
        for(char& c: s)
            if('A'<= c && c <= 'Z') c = c - 'A' + 'a';
            // if (c >= 'A' && c <= 'Z') c += 32;
        return s;
    }
