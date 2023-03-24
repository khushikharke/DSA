#include<iostream>
#include<vector>
#include<map>
using namespace std;

void khushi(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);
}
//1. generate all substr from the given string 
//2. generate all their hash of size 26
// 3 hash the Hash values to club all anagrams in one , to get their frequency count
//4. from freq count, count the ans;
vector<int> getHash(string s, int i, int j){
	/// freq dega ye function
	vector<int> freq(26,0);

	for(int k=i;k<=j;k++){
		char ch =s[k];
		freq[ch-'a']++;
	}
	return freq;
}

int anangram_substring(string s){
	//in map first key is my hash arr ans second key is my freq
	map<vector<int>,int> m;

	for(int i =0;i<s.length();i++){
		for(int j=i;j<s.length();j++){
			// s[i....j]

			vector<int> h = getHash(s,i,j);
			// put it in a map
			m[h]++;
		}

	}
	// pairs combine
	int ans=0;
	for(auto p : m){
		int freq = p.second;
		if(freq >= 2){
			ans+= ((freq)*(freq -1))/2;
		}
	}
	return ans ;
}


int main(){
	khushi();
	string s ;
	cin>>s;
	cout<< anangram_substring(s) <<endl ;
	return 0;
}