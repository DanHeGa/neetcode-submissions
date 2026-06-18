class KthLargest {
    private:
        priority_queue<int> pq;
        int k;

    public:
        KthLargest(int k, vector<int>& nums) {
            for (int num : nums) {
                pq.push(num);
            }
            this->k = k;
        }

        int add(int val) {
            pq.push(val);
            priority_queue<int> aux = pq;

            int i = 1;
            while(i < k){
                aux.pop();
                i++;
            }

            return aux.top();
        }
};

/*
[1, 2, 3, 3]    i= 0  1  2  3 
after max heap -> [3, 3, 2, 1]
add(3) -> [3, 3, 3, 2, 1]
i = 1; k = 3;
    1 [ 3, 3, 2, 1]
    2 [ 3, 2, 1]
    3 not less than k , so does nothing

    pq.top should be = 3; 
*/