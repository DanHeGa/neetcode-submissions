class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(pq.size() > 1) {
            int ele1 = pq.top();
            pq.pop();
            int ele2 = pq.top();
            pq.pop();

            if (ele1 == ele2) {
                cout << "Equal eles: " << ele1 << " " << ele2 << endl;
            } else {
                int newEle = ele1 - ele2;
                pq.push(newEle);
            }
        }

        pq.push(0); //if no elements left, return 0
        return pq.top();
    }
};
