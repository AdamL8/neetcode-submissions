class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result;

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            const auto leftNum = numbers[left];
            const auto rightNum = numbers[right];
            const auto sum = leftNum + rightNum;

            if (sum == target)
            {
                result.emplace_back(left + 1);
                result.emplace_back(right + 1);
                break; 
            }

            if (sum < target)
            {
                ++left;
                continue;
            }

            if (sum > target)
            {
                --right;
                continue;
            }
        }

        return result;
    }
};
