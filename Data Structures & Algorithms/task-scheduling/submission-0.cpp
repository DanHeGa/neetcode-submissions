class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        //order by most frequent through a max heap
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;

        while(!pq.empty() || !q.empty()) {
            time++;

            if (!pq.empty()) {
                int count = pq.top(); //get max ele 
                pq.pop();
                count--;
                if (count > 0) {
                    q.push({count, time + n});
                }
            } else {
                time = q.front().second;
            }

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
