//leetcode peak in mountain arr
class Solution {
public:
 
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int n=arr.size();
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid>0 && mid<n-1)
            {
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                    return mid;
                else if(arr[mid+1]>arr[mid])
                    start=mid+1;
                else
                    end=mid-1;
            }
            else if(mid==0)
            {
                if(arr[mid]>arr[mid+1])
                    return mid;
                else
                    return mid+1;
            }
            else if(mid==n-1)
            {
                if(arr[mid]>arr[mid-1])
                    return mid;
                else
                    return mid-1;
            }
        }
        return -1;
    }
};