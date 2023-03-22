#include<iostream>
#include <queue>
#include <vector>
using namespace std;
void khushi(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
class compare {
public:
	bool operator()(int a, int b ){
		return a<b;
	}
};



int main(){
	khushi();
	int arr[]={10,15,20,13,6,90};
	int n= sizeof(arr)/sizeof(int);
	// max heap;
	priority_queue< int, vector<int>, compare > heap;
	for(int x : arr){
		heap.push(x);
	}
	while(!heap.empty()){
		cout<<heap.top()<<endl;
		heap.pop();
	}

	
	// khushi();
	return 0;
}