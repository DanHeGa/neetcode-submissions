class Solution {
public:
    //Complexity: time = O(n + m), space = O(m)
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> freqT, freqS; //frequency map of t and s
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;

        for (char ele : t) {
            freqT[ele]++;
        }

        int need = freqT.size();
        int have = 0;
        int left = 0;

        for (int r = 0; r < s.length(); r++) {
            //build window map of frequencies
            freqS[s[r]]++;

            //find if it is in freqT
            if (freqT.count(s[r]) && freqS[s[r]] == freqT[s[r]]) {
                have++;
            }

            while (have == need) {
                if (r - left + 1 < resLen) {
                    res = {left, r};
                    resLen = r - left + 1;
                }

                freqS[s[left]]--;
                //check if window is still valid to shrink
                if (freqT.count(s[left]) && freqS[s[left]] < freqT[s[left]]) {
                    have--;
                }

                left++;
            }
        }

        //debug
        cout << "Have: " << have << " need: " << need << endl;
        cout << s.substr(left, resLen) << endl;
        cout << "LEFT: " << left << " res.first: " << res.first << endl;
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
