#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
void khushi(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);

}

int main(){
	khushi();
	int n;
	cin>>n;
	int arr[n];
	unordered_map<int,int> mpp;

	for(int i=0;i<n;i++){
		cin >> arr[i];
		mpp[arr[i]]++;
	}
 	// for(int i=0;i<n;i++){
	// 	hash[arr[i]]+=1;
	// }
	// 
	for(auto it : mpp){
		cout<<it.first<<"-->> "<<it.second<<endl;
	}

 	int q;
	cin>>q;
	while(q--){
		int number;
		cin>>number;
		//fetch
		// cout<<hash[number]<<endl;
		cout<<mpp[number]<<endl;
	}

	return 0;
}