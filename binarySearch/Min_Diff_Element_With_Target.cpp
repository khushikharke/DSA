#include <bits/stdc++.h>
using namespace std;
//return the element giving minimum diff
int minDiffEle(int * arr, int size, int key){
    int ans;
    int start=0;
    int end=size-1;

    while(start<=end){
        int mid = start+(end - start)/2;
        if(arr[mid] == key){
            return arr[mid];
        }
        else if(key > arr[mid]){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
    } 
    int ngbr1=abs(key-arr[start]);
    int ngbr2=abs(key-arr[end]);
   
    return min(ngbr1,ngbr2);
    
}

int main() {
    int size=5;
    int key=12;
 
    int arr[5]= {1, 3, 8, 10, 15};
    int ans= minDiffEle(arr, size, key);
    cout<<"min diff is "<<ans;

   
}