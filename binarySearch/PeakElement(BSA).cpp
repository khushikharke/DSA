class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int start=0;
       int end=n-1;
       while(start<=end){
           int mid=start+(end-start)/2;
           if(mid>0 && mid<n-1){
               if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]){
                   return mid;
               }
               //either go to left or right 
               else if(arr[mid+1]>arr[mid]){
                   // right 
                   start=mid+1;
               }
               else{
                   //left
                   end=mid-1;
               }
           }
           if(mid==0){
               if(arr[0]>arr[1]){
                   return 0;
               }
               else{
                   // start=mid+1
                   start= 1;
               }
           }
           else if(mid==n-1){
               if(arr[n-1]>=arr[n-2]){
                   return n-1;
               }
               else{
                   end= n-2;
               }
           }
       }
       return 0;
    }
};