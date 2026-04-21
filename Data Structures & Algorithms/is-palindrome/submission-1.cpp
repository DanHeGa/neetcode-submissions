class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right) {
            if (!isAlpha((tolower(s[left])))) {
                left++;
                continue;
            }

            if (!isAlpha((tolower(s[right])))) {
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }

    bool isAlpha(char c) {
        if(('A' <= c && c <= 'Z') || 
           ('a' <= c && c <= 'z') ||
           (c >= '0' && c <= '9')) {
            return true;
        } 

        return false;
    }
};
