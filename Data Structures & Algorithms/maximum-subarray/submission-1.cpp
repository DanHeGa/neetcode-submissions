class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        int res = nums[0];

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cout << "i->" << i << " nums[i]: " << nums[i] << " maxSum+: " << maxSum << endl;
            cout << "sum " << maxSum + nums[i] << endl;
            maxSum = max(nums[i], maxSum + nums[i]);
            if (maxSum > res) res = maxSum;
        }

        return res;
    }
};


/*
nums = [2,-3,4,-2,2,1,-1,4]
maxSum = 0

2 or maxSum + 2 ->maxSum = 2
-3 or maxSum + (-3) = -1-> maxSum = -1
4 or maxSum + (4) = 3 ->maxSum = 3...

maxSum = 8

*/