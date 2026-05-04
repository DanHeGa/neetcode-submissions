class Solution {
public:
    bool isValid(string s) {
        stack<int> stck;

        unordered_map<char, char> pairs = {
            {')' , '('},
            {'}' , '{'}, 
            {']' , '['}
        };
        
        for (int i = 0; i < s.length(); i++) {
            if (pairs.count(s[i])) {
                if (!stck.empty() && stck.top() == pairs[s[i]]) {
                    stck.pop();
                } else {
                    return false; //found it, but not his pair
                }
            } else {
                stck.push(s[i]);
            }
        }

        return stck.empty();
    }
};
