class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        if(nums.size()==0){
            return ans;
        }
        ans[0]=first_occ(nums,target);
        ans[1]=last_occ(nums,target);
        return ans;
    }
public:
    int first_occ(vector<int> &nums,int target){
        int start=0;
        int end=nums.size()-1;
        int res1=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==nums[mid]){
                res1=mid;
                end=mid-1;

            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
       
        return res1;
    }
    public:
    int last_occ(vector<int> &nums,int target){
        int start=0;
        int end=nums.size()-1;
        int res2=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==nums[mid]){
                res2=mid;
                start=mid+1;

            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
       
        return res2;
    }

};