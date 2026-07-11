class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        int currMaxReach = 0;
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            maxReach = max(maxReach, nums[i] + i);

            if (i == currMaxReach){
                currMaxReach = maxReach;
                count++;
            }
        }

        return count;
    }
};
