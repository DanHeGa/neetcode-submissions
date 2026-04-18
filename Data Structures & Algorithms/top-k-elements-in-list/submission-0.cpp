class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // put the number frequencies in a hashmap
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        //order them in descending order with a priority queue
        priority_queue<pair<int, int>> ordered_freqs;
        for (auto f : freq) {
            ordered_freqs.push({f.second, f.first});
        }

        //get the top k elements and put them within a vector
        vector<int> res;
        while(k > 0) {
            int num = ordered_freqs.top().second;
            res.push_back(num);
            k--;
            ordered_freqs.pop();
        }

        return res;
    }
};
