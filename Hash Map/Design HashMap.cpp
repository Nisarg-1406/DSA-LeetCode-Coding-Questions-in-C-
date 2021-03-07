    // Using vector of list - 
    vector<list<pair<int,int>>> m_data;
    int m_size = 10000;
    /** Initialize your data structure here. */
    MyHashMap() {
        m_data.resize(m_size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto & li = m_data[key % m_size];
        for (auto & val : li) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        li.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) { //As we getting the key from the vector of list anfd hence const is putten, It is not necessay to put it. 
        const auto &li = m_data[key % m_size];
        if (li.empty()) {
            return -1;
        }
        for (const auto & val : li) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& li = m_data[key % m_size];
        for (auto & val : li) {
            if(val.first == key) { 
                li.remove(val);
                return;
            }
        }
    }
