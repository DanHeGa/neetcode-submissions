class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> uniques;
        int left = 0, maxFreq = 0, res = 0;
        for (int r = 0; r < s.length(); r++) {
            uniques[s[r]]++;
            maxFreq = max(maxFreq, uniques[s[r]]);

            while((r - left + 1) - maxFreq > k){ //r - l == window string length
                uniques[s[left]]--; //char frequency in that window decreases
                left++; // shrink window 
            }

            res = max(res, (r - left + 1));
        }
        
        return res;

    }
};
