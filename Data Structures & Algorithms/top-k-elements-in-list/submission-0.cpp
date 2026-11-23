class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        using Value = int;
        using Frequency = int;
        using FrequencyToValuePair = std::pair<Frequency, Value>;
        std::unordered_map<Value, Frequency> frequencyMap;
        std::priority_queue<FrequencyToValuePair, std::vector<FrequencyToValuePair>, std::less<FrequencyToValuePair>> minHeap;

        for (const auto& num : nums)
        {
            frequencyMap[num]++;
        }

        for (const auto& kvp : frequencyMap)
        {
            minHeap.emplace(kvp.second, kvp.first);
        }

        vector<int> results;
        results.reserve(k);

        for (auto i = 0; i < k; ++i)
        {
            results.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return results;
    }
};
