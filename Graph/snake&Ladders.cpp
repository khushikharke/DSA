#include<iostream>
#include<list>
#include<queue>
using namespace std;
void khushi(){
    // freopen("input.txt","r",stdin);
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
	void bfs(int source,int dest=-1){

		queue<int> q;
		bool *visited = new bool[V];
		int *dist = new int[V];
		int *parent = new int[V];
        // vector<bool> visited(V, false);
        // vector<int> dist(V,0),parent(V);
		for(int i=0;i<V;i++){
			parent[i] = -1;
            visited[i] = 0;
            dist[i] = 0;             
		}

		q.push(source);
		visited[source] = true;
		parent[source] = source;
		dist[source] = 0;

		while(!q.empty()){
			//Do some work for every node
			int f = q.front();
			//cout<<f <<endl;
			q.pop();

			//PUsh the nbrs of current node inside q if they are not already visited
			for(auto nbr : l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					//parent and dist
					parent[nbr] = f;
					dist[nbr] = dist[f] + 1;
					visited[nbr] = true;
				}
			}
		}
		//print the shortest distance
		for(int i=0;i<V;i++){
			cout<<"Shortest dist to "<<i<<" is "<<dist[i] <<endl;
		}


		//print the path from a source to any dest
		if(dest!=-1){
			int temp = dest;
			while(temp!=source){
				cout<<temp<<"-- ";
				temp = parent[temp];
			}
			cout<<source<<endl;
		}

	}
	
	

};
int min_dice_throws(int n, vector<pair<int,int> > snakes, vector<pair<int.int> > ladders){
    vector<int> board(n+1);
    for(auto sp:snakes){
        int s = sp.first;
        int e = sp.second;
        board[s] = e-s;
    }
    for(auto l:ladders){
        int s = l.first;
        int e = l.second;
        board[s] = e-s;
    }
    Graph g(n+1);
    for(int u =1;u<n;u++){
        for(int dice =1;dice <= 6;dice++){
            v=u+dice;
            v=v+board[s];
            if(v<=n){
                g.addEdge(u,v);
            }
        }
    }
}

int main(){
    
}