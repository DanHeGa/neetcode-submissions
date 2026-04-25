class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL = height[0];
        int maxR = height[n - 1];

        int left = 1, right = n - 2;
        int result = 0;
        while (left <= right) {
            if (maxL <= maxR) {
                //calculate left water capacity
                result += max(0, maxL - height[left]);
                if (height[left] > maxL) maxL = height[left];
                left++;
            } else { //maxR < maxL  
                result += max(0, maxR - height[right]);
                if (height[right] > maxR) maxR = height[right];
                right--;
            }
        }

        return result;
    }
};
