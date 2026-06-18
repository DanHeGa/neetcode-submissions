class KthLargest {
    private:
        priority_queue<int, vector<int>, greater<int>> pq;
        int k;

    public:
        KthLargest(int k, vector<int>& nums) {
            for (int num : nums) { //O(n)
                pq.push(num);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
            this->k = k;
        }

        int add(int val) {
           pq.push(val);
           if (pq.size() > k) {
            pq.pop();
           }

           return pq.top();
        }
};

/* first approach O(n) in space and time
[1, 2, 3, 3]    i= 0  1  2  3 
after max heap -> [3, 3, 2, 1]
add(3) -> [3, 3, 3, 2, 1]
i = 1; k = 3;
    1 [ 3, 3, 2, 1]
    2 [ 3, 2, 1]
    3 not less than k , so does nothing

    pq.top should be = 3; 
*/

/* second approach O() in space and time
[1, 2, 3, 3]    i= 0  1  2  3 
constructor
[1, 2, 3, 3], [1, 2, 3, 3] size > k ? [2, 3, 3] : dont pop and continue

after min heap -> [2, 3, 3]
add(3) -> [2, 3, 3], pq.push, if pq.size > k ? pq.pop() : dont pop and continue
return pq.top()

*/