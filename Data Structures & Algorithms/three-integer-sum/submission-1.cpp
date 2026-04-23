class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int a = nums[i];
            int l = i + 1; 
            int r = n - 1;
            while(l < r) {
                int op = a + nums[l] + nums[r];
                if (op == 0) {
                    vector<int> subRes = {a, nums[l], nums[r]};
                    res.push_back(subRes);
                    l++;

                    //avoid dupplicates
                    while(nums[l] == nums[l - 1] && l < r){
                        l++;
                    }

                } else if (op > 0) {
                    r--;
                } else { //op < 0;
                    l++;
                }
            }

        }
        
        return res;
    }
};
