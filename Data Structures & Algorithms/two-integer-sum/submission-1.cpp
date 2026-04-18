class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diffs;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (diffs.find(diff) != diffs.end()) {
                vector<int> res = {diffs[diff], i};
                return res;
            }

            diffs[nums[i]] = i;
        }
        return {};
    };
};