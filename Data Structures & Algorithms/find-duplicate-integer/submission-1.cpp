class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++){

            int numIdx = abs(nums[i]) - 1; //get idx based on array element value
            if (nums[numIdx] < 0) {
                return abs(nums[i]);
            }

            //use abs because it could eventually be a negative number
            nums[numIdx] *= -1;
        }

        return -1;
    }
};
