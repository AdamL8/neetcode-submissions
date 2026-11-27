class Solution {
public:
    bool isPalindrome(string s) {
        string sanitizedStr;
        sanitizedStr.reserve(s.length());

        for (char c : s)
        {
            if (std::isalnum(c))
            {
                sanitizedStr += std::tolower(c);
            }
        }

        return std::equal(
            sanitizedStr.begin(), 
            sanitizedStr.begin() + sanitizedStr.size() / 2, 
            sanitizedStr.rbegin()
        );
    }
};
