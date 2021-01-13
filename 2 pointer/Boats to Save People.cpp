    T.C - O(NlogN)
    
    * We simply maintain 2 pointers start and end. If people[start] + people[end] <= limit meaning both start and end can put in the same boat, hence we increament
    start and decrement end. If people[start] + people[end] > limit meaning only end can be on the boad, hence we decrement end and keep start.
    
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int start = 0;
        int end = people.size() - 1;
        int cnt = 0;
        while (start <= end) {
            if (people[start] + people[end] <= limit) start = start + 1;
            end = end - 1;
            cnt = cnt + 1;
        }
        return cnt;
    }
