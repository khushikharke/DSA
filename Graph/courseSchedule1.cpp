class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        vector<int> indegree(n, 0);
        queue<int> q;

        vector<vector<int>> adj(n);
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> courses;
        while (!q.empty())
        {
            int node = q.front();
            courses.push_back(node);
            q.pop();
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return (courses.size() == n);
    }
};