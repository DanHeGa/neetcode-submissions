class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numIdx;
        for (int i = 0; i < nums.size(); i++) {
            if (numIdx.find(nums[i]) != numIdx.end() && abs(i - numIdx[nums[i]]) <= k) {
                return true;
            }
            
            numIdx[nums[i]] = i;
        } 

        return false;
    }
};