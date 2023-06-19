#include<iostream>
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
    void printList(){
        // iterate over all rows
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            for(auto node : l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    khushi();
    //cout<<"Hello World!";

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.printList();
   return 0;

}