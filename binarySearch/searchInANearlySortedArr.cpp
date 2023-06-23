// in an almost sorted array
#include <bits/stdc++.h>
using namespace std;
// void(khushi){
//     freopen("output.txt","w",stdout);
// }
int bs(int arr[],int start,int end,int x){
    if(end>=start){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid-1]==x && mid>1){
            return (mid-1);
        }
        if(arr[mid+1]==x && mid<end){
            return (mid+1);
        }
        if(arr[mid]>x){
            return bs(arr,start,mid-2,x);
        }
        return bs(arr,mid+2,end,x);
        
    }
    return -1;
}

int main(){
   
    int arr[] = { 3, 2, 10, 4, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = bs(arr, 0, n - 1, x);
    (result == -1)? printf("Element is not present in array") : printf("Element is present at index %d", result);
    return 0;
}
