class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        //get s1 elements frequency
        unordered_map<char, int> freq;
        int need = 0;

        for (char ele : s1) {
            if (++freq[ele] == 1) { //character found
                need++;
            }
        }

        for (auto ele : freq) {
            cout << ele.first << " : " << ele.second << endl;
        }

        int wdSize = s1.size();
        for (int i = 0; i < s2.size(); i++) {
            if (--freq[s2[i]] == 0) {
                cout << "Removing from need "<<s2[i] << " need = " << need << " idx= " << i << endl;
                need--;
            }

            if (i + 1 > wdSize) {
                //substract from the left most element
                if (++freq[s2[i - wdSize]] == 1) {
                    cout << "Add from need "<<s2[i - wdSize] << " need = " << need << " idx= " << i - wdSize << endl;
                    need++;
                } 
            }

            if (need == 0) {
                return true;
            }
        }

        return false;
    }
};
