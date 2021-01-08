    VERY EASY STRING QUESTION - WARM UP
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";
        for (auto x : word1) a = a + x;
        for (auto y : word2) b = b + y;
        return a == b;
    }
