class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        // 2 pointer approach
        while (left < right)
        {
            // 1. Move left pointer forward until it hits an alphanumeric char
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left])))
            {
                ++left;
            }

            // 2. Move right pointer backward until it hits an alphanumeric char
            while (left < right &&!std::isalnum(static_cast<unsigned char>(s[right])))
            {
                --right;
            }

            if (std::tolower(s[left]) != std::tolower(s[right]))
            {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};
