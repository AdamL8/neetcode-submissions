class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() || t.empty())
        { return false; }

        if (s.size() != t.size())
        { return false; }

        std::unordered_map<char, int> seen;

        for (auto i = 0; i < s.size(); ++i)
        {
            seen[s[i]]++;
            seen[t[i]]--;
        }

        return std::all_of(seen.begin(), seen.end(), [](const auto& pair) {
            return pair.second == 0;
        });
    }
};
