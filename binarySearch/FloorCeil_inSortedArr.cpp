pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	//floor
	sort(arr,arr+n);
	int s=0;
	int e=n-1;
	int res1=-1;
	int res2=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==x){
			// res1=arr[mid];
			// res1=arr[mid];
			return{arr[mid],arr[mid]};
		}
		else if(arr[mid]<x){
			res1=arr[mid];
			s=mid+1;

		}
		else{
			res2=arr[mid];
			e=mid-1;
		}
	}
	return {res1,res2};
}