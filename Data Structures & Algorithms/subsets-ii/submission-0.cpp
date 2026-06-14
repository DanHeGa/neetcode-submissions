class Solution {
public:
    vector<vector<int>> res;

    void dfs(int idx, vector<int> sub, vector<int> nums) {
        if (idx >= nums.size()) {
            res.push_back(sub);
            return;
        }

        sub.push_back(nums[idx]);
        dfs(idx + 1, sub, nums);

        int ele = nums[idx];
        while(idx + 1 < nums.size() && nums[idx + 1] == ele) {
            idx++;
        }

        sub.pop_back();
        dfs(idx + 1, sub, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(), nums.end());
        dfs(0, sub, nums);
        return res;
    }
};
