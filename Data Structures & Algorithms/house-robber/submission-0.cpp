class Solution {
public:
    int rob(vector<int>& nums) {

        int rob1 = 0;
        int rob2 = 0;
        for (int currHouse : nums) {
            int currMaxRob = max(currHouse + rob1, rob2);
            rob1 = rob2;
            rob2 = currMaxRob;
        }

        return rob2;
    }
};
