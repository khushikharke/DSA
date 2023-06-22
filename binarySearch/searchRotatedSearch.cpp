class Solution {
    int bs(vector<int>& nums, int target, int start, int end){
        while(start<=end){
           int mid=start+(end-start)/2;
           if(nums[mid]==target){
               return mid;

           }
           else if(nums[mid]<target){
               start=mid+1;
           }
           else{
               end=mid-1;
           }
       }
       return -1;
    }

    int minIndex(vector<int> &nums){
        int n = nums.size();
        int start=0, end = n-1, min_el = -1;
        if(n==1) return 0;
        while(start<=end){
           long long mid=start+(end-start)/2;
           long long next=(mid+1)%n;
           long long prev=(mid-1+n)%n;
           if(nums[mid]<nums[next] and nums[mid]<nums[prev]){
              min_el=mid;
               break;

           }
           else if(nums[mid]<nums[end]){
               end=mid-1;
           }
           else{
               start=mid+1;
           }dddd
       }
       return min_el;
    }
public:
    int search(vector<int>& nums, int target) {
       int index = minIndex(nums);
       int n =nums.size();

        int first = bs(nums,target,0,index-1);
        int second= bs(nums,target,index,n-1);
        cout<<first;
        cout<<second;

        if(first!=-1){
            return first;
        }
        else{
            return second;
        }
    }
    
};