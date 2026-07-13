class Solution {
public:
    vector<string> res;
    
    void dfs(string startFly, unordered_map<string, vector<string>> &adjList, vector<vector<string>>& tickets) {
        while(!adjList[startFly].empty()) {
            string nextFly = adjList[startFly].back();
            adjList[startFly].pop_back();
            dfs(nextFly, adjList, tickets);
        }

        res.push_back(startFly);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.rbegin(), tickets.rend()); //sort them in lexicographical order

        //build adjacency list
        unordered_map<string, vector<string>> adjList;
        for (auto &ticket : tickets) {
            string origin = ticket[0];
            string destination = ticket[1];
            adjList[origin].push_back(destination);
        }

        dfs("JFK", adjList, tickets);

        reverse(res.begin(), res.end());
        return res;
    }
};
