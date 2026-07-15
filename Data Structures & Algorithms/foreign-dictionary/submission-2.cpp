class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, int> indegree; //number of dependencies
        unordered_map<char, vector<char>> adjList; //each node and it's list of dependants

        for (string word : words) {
            for (char c : word) {
                indegree[c] = 0;
                adjList[c];
            }
        }

        string res = "";
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int minLen = min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2) {
                return "";
            }

            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    char first = w1[j];
                    char second = w2[j];
                    adjList[first].push_back(second); //second depends on first
                    indegree[second]++; //plus one dependency for second
                    break;
                }
            }
        }

        queue<char> q;
        for (auto &ele : indegree) {
            if (ele.second == 0) {
                q.push(ele.first);
            }
        }

        while(!q.empty()) {
            char smaller = q.front();
            q.pop();
            res += smaller;

            for (char dependant : adjList[smaller]) {
                indegree[dependant]--;
                if (indegree[dependant] == 0) {
                    q.push(dependant);
                }
            }
        }
        
        if (res.length() != indegree.size()) {
            return "";
        }

        return res;
    }
};
