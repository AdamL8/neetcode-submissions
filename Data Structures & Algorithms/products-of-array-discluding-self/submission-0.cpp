class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results = vector<int>(nums.size(), 1);
        vector<int> prefix = vector<int>(nums.size(), 1);
        vector<int> postfix = vector<int>(nums.size(), 1);

        // Start at 1 to be within safe bounds
        for (int i = 1; i < nums.size(); ++i)
        {
            // prefix[i] means: the product of everything strictly BEFORE index i
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Start at size - 2 to be within safe bounds
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            // postfix[i] means: the product of everything strictly AFTER index i
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            results[i] = prefix[i] * postfix[i];
        }

        return results;
    }
};
