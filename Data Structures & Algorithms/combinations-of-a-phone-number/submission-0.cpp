class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> res;
        if (n == 0) return res;
         
        //create a hashmap with each digit's respective letters
        unordered_map<int, string> digitStr = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        res = {""};
        for (char digit : digits) {
            string strVal = digitStr[digit - '0'];
            cout << "string val " << strVal << endl;

            vector<string> newCombs;

            for (string currComb : res){
                for (char chr : strVal) {
                    newCombs.push_back(currComb + chr);
                    cout << "Appended " << currComb + chr << " ";
                }
            }

            res = move(newCombs);
        }

        return res;

    }
};
