class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() || t.empty())
        { return false; }

        if (s.size() != t.size())
        { return false; }

        std::ranges::sort(s);
        std::ranges::sort(t);

        for (auto i = 0; i < s.size(); ++i)
        {
            if (s[i] != t[i])
            { return false; }
        }

        return true;
    }
};
