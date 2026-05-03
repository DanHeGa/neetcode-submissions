class Solution {
public:
    //use of deque (double ended queue)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> q;
        int r = 0, l = 0;

        while(r < n) {
            //pop smaller indexes in deque
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r); //just the index

            //get out of limit elements from the deque
            if (l > q.front()) {
                q.pop_front();
            }

            if (r + 1 >= k) {
                //add max of window before moving it
                res.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }

        return res;

    }
};
