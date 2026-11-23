class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result;

        for (const auto& str : strs)
        {
            const auto& strLength = str.length();
            result.append(std::to_string(strLength));
            result.push_back('#');
            result.append(str);
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> results;
        size_t i = 0;

        while (i < s.length())
        {
            size_t hashPos = s.find('#', i);
            int len = std::stoi(s.substr(i, hashPos - i));
            results.push_back(s.substr(hashPos + 1, len));
            i = hashPos + 1 + len;
        }

        return results;
    }
};
