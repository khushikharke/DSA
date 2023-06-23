int bs(int arr[],int start,int end,int x,)
    int res=-1;
    
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]>x){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}

int first1(int arr[],int x){
    int start=0;
    int end=1;
    while(arr[end]<x){
        start=end;
        end=end*3;
    }
    return bs(arr,start,end,x);
}

