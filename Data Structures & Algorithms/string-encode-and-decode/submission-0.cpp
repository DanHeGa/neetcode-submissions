class Solution {
public:

    string encode(vector<string>& strs) {
        string coded = "";
        vector<int> lengths;
        for (string str : strs) {
            lengths.push_back(str.size());
        }

        for (int len : lengths) {
            coded += to_string(len) + ",";
        }

        coded += "#";
        for (string str : strs) {
            coded += str;
        }

        cout << "coded -> " << coded << endl;
        return coded;
    }

    vector<string> decode(string s) {
        int hashIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                hashIdx = i;
                break;
            }
        }

        vector<string> res;
        int hashPtr = hashIdx;
        int i = 0;
        while (s[i] != '#') {
            if (s[i] == ',') {
                i++;
                continue;
            }

            string numStr = "";
            while (s[i] != ',' && s[i] != '#') {
                numStr += s[i];
                i++;
            }
            
            int len = stoi(numStr);
            
            res.push_back(s.substr(hashPtr + 1, len));
            hashPtr += len;
        }

        return res;
    }
};
