#include<iostream>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;
void khushi(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

class Car {
public:
	string id;
	int x,y;

	Car(string id, int x, int y){
		this->id=id;
		this->x=x;
		this->y=y;
	}
	
	int dist() const{
		return x*x + y*y; // for dist using euclidean formula
	}
};
 
class CarCompare{
public:
	bool operator()(const Car A, const Car B){
		return A.dist() < B.dist();//max heap 
	}
};

void print_NearestKCabs(vector<Car> cars, int k  ){
	priority_queue<Car, vector<Car>, CarCompare>  max_heap(cars.begin(),cars.end()+k);// max heap of size k 

	// at this pnt first k cars are in heap
	for(int i=k; i<cars.size();i++){
		auto car = cars[i];
		if(car.dist() < max_heap.top().dist()){
			//replace it 
			max_heap.pop();
			// removes largest/root node
			max_heap.push(car);
		}
		
	}
	vector<Car> op;

	while(!max_heap.empty()){
		// cout<< max_heap.top().id<<endl;
		op.push_back(max_heap.top());
		max_heap.pop();
	}


	reverse(op.begin(), op.end());
	for(auto car : op){
		cout<< car.id << endl;
	}
	return ;
}



int main(){
	khushi();
	int N,k;
	cin>>N>>k;

	string id;
	int x,y;

	vector<Car> cars;
	for(int i=0;i<N;i++){
		cin>>id >> x>> y;
		Car car(id,x,y);
		cars.push_back(car);
	}

	print_NearestKCabs(cars,k);

	
	// khushi();
	return 0;
} 