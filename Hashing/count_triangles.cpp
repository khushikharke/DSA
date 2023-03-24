#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

void khushi(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);
}
int count_triangles(vector<pair<int,int> > & points){
	unordered_map <int,int> freq_x , freq_y;
	int ans=0;
// count freq
	for(auto p : points){
		int x = p.first;
		int y= p.second;


		freq_x[x]++;
		freq_y[y]++;
	}
	int count =0;
	for(auto p : points){
		int x = p.first;
		int y= p.second;

		int cntx = freq_x[x];
		int cnty = freq_y[y];

		if(cntx>=1 && cnty>=1){
			
			count +=(cntx - 1)*(cnty - 1);
	    }
	}
	return count;
}


int main(){
	khushi();
	int N ;
	cin >> N;

	vector<pair<int,int > > points;


	for(int i =0;i<N ;i++){
		int x,y;
		cin>>x>>y;
		points.push_back(make_pair(x,y));
	}
	cout<< count_triangles(points);
	return 0;
}