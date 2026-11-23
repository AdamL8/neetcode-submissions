class LRUCache {
public:
    LRUCache(int capacity)
    : m_capacity(capacity)
    {
    }
    
    int get(int key) {

        auto maybeFoundNodeItr = m_keyToNode.find(key);

        if (maybeFoundNodeItr != m_keyToNode.end())
        {
            // Move to front
            m_recencyList.splice(m_recencyList.begin(), m_recencyList, maybeFoundNodeItr->second);
            return maybeFoundNodeItr->second->second;
        }

        return -1;
    }
    
    void put(int key, int value) {
        auto maybeFoundNodeItr = m_keyToNode.find(key);

        if (maybeFoundNodeItr != m_keyToNode.end())
        {
            // Update value associated with key in linked list
            maybeFoundNodeItr->second->second = value;

            // Move to front
            m_recencyList.splice(m_recencyList.begin(), m_recencyList, maybeFoundNodeItr->second);
            return;
        }

        // Evict LRU
        if (m_recencyList.size() >= m_capacity)
        {
            auto toEvict = m_recencyList.back();
            m_keyToNode.erase(toEvict.first);
            m_recencyList.pop_back();
        }

        // Insert new element
        m_recencyList.push_front({key, value});
        m_keyToNode[key] = m_recencyList.begin();

    }

private:
    int m_capacity = 0;

    std::list<std::pair<int, int>> m_recencyList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_keyToNode;
};
