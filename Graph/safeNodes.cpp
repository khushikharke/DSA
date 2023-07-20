class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        // code here
        vector<int> adj[n]; // array for reverse a list
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            // it is neighbour of i.e so (i->it) so we need to convert (it->i)
            for (auto it : graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++; // because 'it' goes to 'i'
            }
        }
        // now checking the terminal node
        queue<int> q; // creating an empty queue
        vector<int> safeNode;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNode.push_back(node);
            // then go for adj[] node and check its neighbour node
            for (auto it : adj[node])
            {
                // first indegree reduce
                indegree[it]--;
                // check if indegree is zero then push into queue
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};