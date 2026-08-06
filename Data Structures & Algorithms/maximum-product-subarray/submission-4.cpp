class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        //global and local max Subarray products
        int maxProduct = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tmpCurrMax = currMax;
            currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], tmpCurrMax * nums[i], currMin * nums[i]});
            
            maxProduct = max(maxProduct, currMax);
        }

        return maxProduct;
    }
};
