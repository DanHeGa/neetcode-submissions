class Solution {
public:
    int MAX_LENGTH = 26;
    string makeHash(const string& str) {
        string hash;
        vector<int> freq(MAX_LENGTH, 0);

        for (char c : str) {
            freq[c - 'a']++;
        }

        for(int i = 0; i < MAX_LENGTH; i++) {
            hash.append(to_string(freq[i]));
            hash.append("$");
        }

        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> arrays;
        vector<vector<string>> res;

        for (string str : strs) {
            string key = makeHash(str);
            // if not found, insert the new key with the vector index
            if (arrays.find(key) == arrays.end()) {
                arrays[key] = res.size();
                res.push_back({});
            }
            
            res[arrays[key]].push_back(str);
        }

        return res;
    }
};
