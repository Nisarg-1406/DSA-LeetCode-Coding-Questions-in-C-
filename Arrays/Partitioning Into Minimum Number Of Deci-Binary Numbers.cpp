    int minPartitions(string n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return *max_element(begin(n), end(n)) - '0';
    }
