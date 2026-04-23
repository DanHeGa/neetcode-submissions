class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left = 0; 
        int right = n - 1;
        int maxVol = 0;
        while (left < right) {
            int volume = (right - left) * min(heights[left], heights[right]);
            maxVol = max(maxVol, volume);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxVol;
    }
};
