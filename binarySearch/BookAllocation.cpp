
class Solution 

{
    private:
        bool isvalid(int A[],int N,int M,int max){
            int students=1;
            int sum=0;
            for(int i =0;i<N;i++){
                sum=sum+A[i];
                if(sum>max){
                    students++;
                    sum=A[i];
                }
                
                if(students>M){
                    return false;
                }
                if(M>N){
                    return false;
                }
                
            }
            return true;
        }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int end=0;
        int start=0;
        int res=-1;
        for(int i =0;i<N;i++){
            start=max(start,A[i]);
            end=end+A[i];
        }
        
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isvalid(A,N,M,mid)){
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
        
    }
};