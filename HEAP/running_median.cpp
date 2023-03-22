#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void khushi(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}


int main(){
	khushi();
	priority_queue<int> leftHeap;
	priority_queue<int, vector<int> , greater<int> > rightHeap;

	int d;
	cin>>d;
	leftHeap.push(d);

	float median=d;
	cout<<median<<" ";

	cin>>d;

	while(d!=-1){
		if(leftHeap.size()>rightHeap.size()){
			//rebalancing
			if(d < median){
				rightHeap.push(leftHeap.top());
				leftHeap.pop();

				leftHeap.push(d);
			}
			else{
				rightHeap.push(d);
			}
			median=(leftHeap.top() + rightHeap.top()) / 2.0;

		}
		else if(leftHeap.size() == rightHeap.size()){
			if(d<median){
				leftHeap.push(d);
				median=leftHeap.top();

			}
			else{
				rightHeap.push(d);
				median=rightHeap.top();
			}

		}
		else {
			if(d<median){
				leftHeap.push(d);
			}
			else{
				//rebalance 
				leftHeap.push(rightHeap.top());
				rightHeap.pop();

				rightHeap.push(d);
			}
			median= (leftHeap.top()+rightHeap.top())/2.0;
		}
		cout<< median<< " ";
		cin>>d;
	}
	return 0;
}