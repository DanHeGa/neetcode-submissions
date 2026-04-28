class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0, right = 0;
        int maxLen = 0;
        
        unordered_set<int> uniques;
        while(right < n) {
            while(uniques.find(s[right]) != uniques.end()) {
                uniques.erase(s[left]);
                left++;
            }

            uniques.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
