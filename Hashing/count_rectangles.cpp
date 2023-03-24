#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

void khushi(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);
}

class Point{
public:
	int x;
	int y;

	Point(){

	}
	Point(int x,int y){
		this->x=x;
		this->y=y;
	}
};
// comparator class
class compare{
public:
	bool operator()(const Point p1, const Point p2){
		if(p1.x==p2.x){
			return p1.y<p2.y;
		}
		return p1.x<p2.x;
	}



};

int count_rectangles(vector<Point> points){
	// 1. insert all pnts in set
	int ans =0;
	set<Point,compare> s;
	for(Point p : points){
		s.insert(p);
	}

//2. brute for two + two lookups
	for(auto it = s.begin();it!=prev(s.end());it++){
		for(auto jt =next(it);jt!= s.end();jt++){
			Point p1 =  *it;
			Point p2 = *jt;


			// check for valid pnts no doubles
			if(p2.x ==p1.x or p2.y == p1.y){
				continue;
			}
			// p3,p4
			Point p3(p1.x ,p2.y);
			Point p4 (p2.x , p1.y);

			// lookup
			 if(s.find(p3)!= s.end() and s.find(p4)!=s.end()){
			 	ans+= 1;
			 }


		}
	}
	return ans/2;
}
int main(){
	khushi();
	int N ;
	cin>> N ;
	int x,y;
	vector<Point> points;

	for(int i =0;i<N;i++){
		cin>>x>>y;
		Point p(x,y);

		points.push_back(p);

	}
	cout<<count_rectangles(points)<<endl;
	return 0;
}