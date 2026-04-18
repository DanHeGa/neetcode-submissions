class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int i = 0, streak = 0, curr = nums[0], res = 0;

        while(i < nums.size()) {
            if (nums[i] != curr) {
                curr = nums[i];
                streak = 0;
            }
            while (i < nums.size() && nums[i] == curr) {
                i++;
            }

            curr++;
            streak++;
            if (streak > res) res = streak;
        }

        return res;
    }
};
