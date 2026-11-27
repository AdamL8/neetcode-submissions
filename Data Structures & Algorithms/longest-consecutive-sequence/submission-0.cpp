class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
        { return 0; }

        std::sort(nums.begin(), nums.end());

        int result = 1;
        int candidateResult = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            // Skip duplicates without resetting the streak
            if (nums[i] == nums[i - 1]) {
                continue; 
            }
            
            if (nums[i] == nums[i - 1] + 1) {
                ++candidateResult;
                result = std::max(result, candidateResult);
            }
            else {
                candidateResult = 1; // Reset streak to 1 (counting the current number)
            }
        }

        return result;
    }
};
