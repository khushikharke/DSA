#include<iostream>
#include<queue>
using namespace std;

//doubly ll lib function
#include<list>
void khushi(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
class Graph{
    int V;
    list<int> *l; 
public:
    Graph(int v){
        V=v;
        l=new list<int>[V]; 
    }
    void addEdge(int i,int j , bool undir=true){
         l[i].push_back(j);
         if(undir){
            l[j].push_back(i);

         }

    }

    void bfs(int source){
        queue<int> q;
        bool *vis = new bool[V];

        q.push(source);
        vis[source]=true;

        while(!q.empty()){
            int f =q.front();
            cout<<f<<endl;
            q.pop();

            // push curr node neighbours 

            for(auto neigh : l[f]){
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh]=true;
                }
            }
    }   }
};

int main(){
    khushi();

    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.bfs(1);
   return 0;

}