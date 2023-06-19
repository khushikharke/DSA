 #include<iostream>
 #include<unordered_map>
 #include<vector>
 using namespace std;
 #include<list>
 void khushi(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
class node{
    public:
        string name;
        list<string> neigh;

        node (string name ){
            this->name=name;
    }
};
class Graph{
    //all nodes 
    // search where is node
    unordered_map(string,node *) m;
    public:
        Graph(vector<string> cities){
            for(auto city : cities){
                m[city] = new node(city);
            }

        }
    void addEdge(string x, string y, bool undir=false){
        m[x]->neigh.push_back(y);
        if(undir){
            m[y]->neigh.push_back(x);
        }
    }
    
    void printAdjList(){
        for(auto citypair : m){
            auto city = citypair.first;
            node * node = citypair.second;
            cout<<city<<"--->";

            for(auto n:node->neigh){
                cout<<n<<" ,";
            }
            cout<<endl;

        } 
    }
         

};
 int main(){
    khushi();
    vector<string> cities ={"Delhi","London","Paris","New York"};
    Graph g(cities);
    g.addEdge("Delhi","London");
    g.addEdge("New York","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");
    
    g.printAdjList();
    return 0;
 }