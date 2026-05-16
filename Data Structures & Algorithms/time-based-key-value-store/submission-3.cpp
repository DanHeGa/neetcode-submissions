class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    
    //space should: O(n*m)
    TimeMap() {
        unordered_map<string, vector<pair<string, int>>> mp = {};
    }
    
    //Should: O(1)
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    //Should: O(logn)
    string get(string key, int timestamp) {
        vector<pair<string, int>> emotions = mp[key];
        cout << "got emotions " << emotions.size() << endl;

        int n = emotions.size();
        int left = 0, right = n - 1;
        string bestEm = "";

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (emotions[mid].second == timestamp) {
                return emotions[mid].first; //emotion at that moment
            } 

            if (emotions[mid].second <= timestamp) {
                left = mid + 1;
                bestEm = emotions[mid].first;
            } else { 
                right = mid - 1;
            }
        }

        return bestEm;
    }
};
