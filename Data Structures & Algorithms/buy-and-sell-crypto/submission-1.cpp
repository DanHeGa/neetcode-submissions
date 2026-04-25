class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0; 
        int right = 1;
        int n = prices.size();

        int maxP = 0;
        while (right < n) {
            if (prices[left] > prices[right]) {
                left = right;
            } else {
                maxP = max(maxP, prices[right] - prices[left]);
            }

            right++;
        }

        return maxP;
    }
};
