// #include<iostream>
// using namespace std;
// class Graph{
//     int vertices;
//     vector<vector<int>> adjlist;
//     public:
//         Graph(int V) : vertices(V), adjList(V) {}

//         void addEdge(int src, int dest) {
//         adjList[src].push_back(dest);

//         bool dfs(int start, vector<int> &vis, stack<int> ordered)
//     }

// };
//     void khushi(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// }
// int main(){
//     khushi();
//     return 0;
// }
class Solution

{
private:
    bool dfs(int node, int vis[], vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto ngbr : adj[node])
        {
            if (!vis[ngbr])
            {
                dfs(ngbr, vis, adj, st);
            }
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};