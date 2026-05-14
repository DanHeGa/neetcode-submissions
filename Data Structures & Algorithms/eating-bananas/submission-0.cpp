class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = ranges::max(piles);
        int minTime = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            //get total needed hours for that rate 
            int neededTime = 0;
            for (int ele : piles) {
                if (ele % mid == 0) {
                    neededTime += ele / mid;
                } else {
                    neededTime += ele / mid + 1;
                }
            }

            if (neededTime <= h) { //viable minimum time
                minTime = mid;
                right = mid - 1; //keep looking for minimum time
            } else { // too slow, add to left
                left = mid + 1;
            }
        }

        return minTime;
    }
};
