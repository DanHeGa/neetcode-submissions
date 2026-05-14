class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int min = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            cout << "mid -> " << mid <<  " for nums -> " << nums[mid] <<  endl;

            if (nums[mid] <= nums[n - 1]){
                min = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return nums[min];
    }
};
