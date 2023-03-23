#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void khushi(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);

}
int count_triplets(vector<int>arr , int r){


	int n =arr.size();

	unordered_map<long,long> left_freq;
	unordered_map<long,long> right_freq;

	// initialise right with freq and left =0
	for(auto x: arr){
		right_freq[x]++;
		left_freq[x]=0;
	}

	// compute ans
	int ans=0;
	for(int i=0;i<n;i++){
		right_freq[arr[i]]--;

		if(arr[i]% r ==0){

			long b=arr[i];
			long a =arr[i]/r;
			long c=arr[i]*r;

			ans+=left_freq[a]* right_freq[c];
		}

		left_freq[arr[i]]++;

	}
	return ans;
}
int main(){
	khushi();
	int n,r;
	cin>>n>>r;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];	
	}

	cout<<count_triplets(arr,r);

	return 0;
}