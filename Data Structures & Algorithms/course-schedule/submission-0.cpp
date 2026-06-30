class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //prerequisites lists acts as the adj list
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);

        //get indegree of each node and construct graph adj list
        for (vector<int>& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];

            adjList[prerequisite].push_back(course);
            indegree[course]++;
        }

        //get 0-indegree courses first
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> courseList;
        while(!q.empty()) {
            int currCourse = q.front();
            q.pop();
            courseList.push_back(currCourse);

            for (int dependant : adjList[currCourse]) {
                indegree[dependant]--;

                if (indegree[dependant] == 0) {
                    q.push(dependant);
                }
            }
        }

        if (courseList.size() != numCourses) {
            return false;
        } else {
            return true;
        }

    }
};
