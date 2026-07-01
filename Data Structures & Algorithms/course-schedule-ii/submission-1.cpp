class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> res;

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];

            adjList[prereq].push_back(course);
            indegree[course]++;
        }

        //push 0-indegree courses in the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        if (q.size() == 0) {
            return res;
        }

        while(!q.empty()) {
            int course = q.front();
            q.pop();
            res.push_back(course);

            for (int dependant : adjList[course]){
                indegree[dependant]--;
                if (indegree[dependant] == 0) {
                    q.push(dependant);
                }
            }
        }

        if (res.size() != numCourses) {
            return {};
        } else {
            return res;
        }

    }
};


/* 
indegree
    0 0
    1 0
    2 0
    3 0

adj list (dependant courses of each course)
0: []
1: [0]
2: [1]
3: [2]

q=[]

res=[3, 2, 1, 0]

courses = [[0,1],[1,2],[2,3]]

Invalid case
courses = [[0,1],[1,2],[2,0]]

0 1
1 1
2 1

0 : [2]
1 : [0]
2 : [1]

no one enters the queue (cycle detected)
res = [] <- returned value
*/