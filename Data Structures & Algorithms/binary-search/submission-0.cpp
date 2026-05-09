class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            cout << mid <<" -> nums[mid]: " << nums[mid] << endl;
            if (nums[mid] == target){
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else { //nums[mid] > target
                right = mid - 1;
            }
        }

        return -1;
    }
};
