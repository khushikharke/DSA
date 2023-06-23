#include<bits/stdc++.h>
using namespace std;
int bs(int arr[],int start,int end,int x){
    while(start<=end){
            int mid=start+(end-start)/1;
            if(arr[mid]==x){
               return mid;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }

           else{
                start=mid+1;
            }
        }
        return -1;
}
int findIndex(int arr[],int x){
    int start=0;
    int end=1;
    while(arr[end]<x){
        start=end;
        end=end*2;
    }
    return bs(arr,start,end,x);
}