class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //prerequisites lists acts as the adj list
        vector<vector<int>> adjList(numCourses); //space O(V + E) will store all vertices with their respective edges
        vector<int> indegree(numCourses, 0); //space O(V) for num of courses 

        //get indegree of each node and construct graph adj list
        for (vector<int>& pre : prerequisites) { //time O(n) will iterate through the hole input vector
            int course = pre[0];
            int prerequisite = pre[1];

            adjList[prerequisite].push_back(course);
            indegree[course]++;
        }

        //get 0-indegree courses first
        queue<int> q; //space O(m), the worse case would be all courses with no prerequisites (store all courses in queue)
        for(int i = 0; i < numCourses; i++) {//time O(m) for num of courses
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> courseList;
        while(!q.empty()) { //time O(V+E) all egdes of all nodes
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
