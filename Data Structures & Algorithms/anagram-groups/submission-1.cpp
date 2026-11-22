class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
        { return {}; }

        std::unordered_map<string, vector<string>> groups;

        for (const auto& s : strs)
        {
            auto key = s;
            std::ranges::sort(key); 

            groups[key].emplace_back(s);
        }

        vector<vector<string>> results;
        results.reserve(groups.size());

        for (const auto& kvp : groups)
        {
            results.push_back(kvp.second);
        }

        return results;
    }
};
