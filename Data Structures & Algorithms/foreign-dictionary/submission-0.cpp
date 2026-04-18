#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    unordered_map<char, bool> visited;
    vector<char> res;
    unordered_map<char, vector<char>> adjList;

    //topological sort
    bool dfs(char c) {
        if (visited.count(c)) {
            return visited[c]; //found a cycle
        }
        visited[c] = true;
        for (char &ele : adjList[c]) {
            if (dfs(ele)) {
                return true; //found cycle
            }
        }
        visited[c] = false;
        res.push_back(c);
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        //build the graph (use an adjacency list)
        for(auto &w : words) {
            for (char &c : w) {
                adjList[c];
            }
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int minLen = min(s1.size(), s2.size());

            if (s1.size() > s2.size() && s1.substr(0, minLen) == s2) {
                return "";
            }

            for (int j = 0; j < minLen; j++){
                if (s1[j] != s2[j]){
                    adjList[s1[j]].push_back(s2[j]);
                    break;
                }
            }
        }

        for (auto &ele : adjList){
            if(dfs(ele.first)) return "";
        }

        reverse(res.begin(), res.end());
        return string(res.begin(), res.end());
    }
};
