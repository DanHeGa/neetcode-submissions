class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    void dfs(int i, int sum, int& target, vector<int>& nums) {
        if (sum == target) {
            res.push_back(subset);
            return;
        } 
        if (i >= nums.size() || sum > target) {
            return;
        }

        subset.push_back(nums[i]);
        dfs(i, sum + nums[i], target, nums);

        subset.pop_back();
        dfs(i + 1, sum, target, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, 0, target, nums);
        return res;
    }
};
