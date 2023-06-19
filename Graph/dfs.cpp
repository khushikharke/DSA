#include<iostream>
#include<list>
#include<queue>
using namespace std;
void khushi(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}


class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}
    vector<int> ls;
	vector<int> dfsHelper(int node, vector<bool> visited){
		visited[node] = true;
		//cout<<node<<",";
        ls.push_back(node);
		//make a dfs call on all its unvisited neighbours
		for(int nbr : l[node]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
		return ls;

	}

	void dfs(int source){
		//bool *visited = new bool[V]{0};
        vector<bool> visited(V,false);
		dfsHelper(source,visited);
        return;
	}
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
	g.dfs(1);
	return 0;
}