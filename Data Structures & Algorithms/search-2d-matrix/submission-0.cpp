class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            int col = mid % m;
            int row = mid / m;

            if (matrix[row][col] == target) {
                return true;
            }

            if (matrix[row][col] < target) {
                left = mid + 1;
            } else { //matrix[row][col] > target
                right = mid - 1;
            }
        } 

        return false;
    }
};
