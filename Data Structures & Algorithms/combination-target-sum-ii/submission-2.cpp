class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i, int sum, vector<int>& sub, vector<int>& nums, int target) {
        if (sum == target) {
            res.push_back(sub);
            return;
        }

        if (i >= nums.size() || sum > target) {
            return;
        }

        sub.push_back(nums[i]);
        dfs(i + 1, sum + nums[i], sub, nums, target);

        int ele = nums[i];
        while(i + 1 < nums.size() && nums[i + 1] == nums[i]) {
            i++;
        }

        sub.pop_back();
        dfs(i + 1, sum, sub, nums, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int i = 0, sum = 0;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        dfs(i, sum, sub, candidates, target);
        return res;
    }       
};
