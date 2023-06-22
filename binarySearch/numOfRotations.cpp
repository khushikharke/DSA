class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	   int start=0;
	   int end=n-1;
	  
	   while(start<=end){
	       //sorted arr
	       if(arr[start]<=arr[end]){
	           return start;
	       }
	       //rotated
	       
	       int mid=start+(end-start)/2;
	       
	      // int next=(mid+1)%n;
	       //int prev=(mid+n-1)%n;
	       
	       if(arr[mid]<arr[(mid+1)%n] and arr[mid]<arr[(mid+n-1)%n]){
	           return mid;
	       }
	       else if(arr[start]<=arr[mid]){
	           //sorted left side
	           start=(mid+1);
	       }
	       else{
	           end=mid-1;
	       }
	   }
	   return 0;
	   
	}

};