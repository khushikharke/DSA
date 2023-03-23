#include<iostream>
#include<map>
using namespace std;

void khushi(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);

}

int main(){
	khushi();

	string s;
	cin>>s;

	// int hash[256]={0};
	map<char,int >mp;

	for(int i=0;i<s.size();i++){
		mp[s[i]]++;
	}

	int q;
	cin>>q;
	while(q--){
		char c;
		cin>>c;
		//fetch
		cout<<mp[c] << endl;

	}
	return 0;
}