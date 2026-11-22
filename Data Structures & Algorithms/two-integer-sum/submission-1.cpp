class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int, int> dict;

        for (auto i = 0; i < nums.size(); ++i)
        {
            const auto diff = target - nums[i];

            auto foundItr = dict.find(diff);

            if (foundItr != dict.end())
            {
                return vector<int>{foundItr->second, i};
            }

            dict.insert({nums[i], i});
        }

        return vector<int>{};
    }
};
