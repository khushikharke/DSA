#include<iostream>
#include<queue>
using namespace std;
void khushi(){
	freopen("input.txt" ,"r",stdin);
	freopen("output.txt","w",stdout);
}
int join_ropes(int ropes[], int n){
	// inside min heap
	priority_queue<int, vector<int> , greater<int> > pq(ropes,ropes+n);

	int cost=0;
	while(pq.size()>1){
		int A=pq.top();
		pq.pop();
		int B=pq.top();
		pq.pop();

		int new_rope=(A+B);
		cost=cost+new_rope; 
		pq.push(new_rope);
	}
	
	return cost;
}

int main(){
	khushi();
	int ropes[]= {4,3,2,6};
	int n=4;
	cout<<join_ropes(ropes,n)<<endl;
	return 0;

}