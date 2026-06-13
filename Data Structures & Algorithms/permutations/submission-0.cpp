class Solution {
public:
    vector<vector<int>> res;

    //using a lambda function to practice them
    void dfs(int subIndex, vector<int> sub, vector<bool> used, vector<int>& nums) {
        if (subIndex == nums.size()) {
            res.push_back(sub);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            //check if element was already used
            if (!used[i]) {
                used[i] = true;
                sub[subIndex] = nums[i];
                dfs(subIndex + 1, sub, used, nums);
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int> sub(n);
        dfs(0, sub, used, nums);
        return res;
    }
};
