class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            cout << "mid -> " << mid << " nums[mid] = " << nums[mid] << endl;
            //check if left array is sorted
            if (nums[left] <= nums[mid]) {
                //check if target is within left araray
                cout << " l = " << left << ", r = " << right << endl;
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { //check rigth array
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
