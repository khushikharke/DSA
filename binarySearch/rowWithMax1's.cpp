class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int x=0;
	    int y = m-1;
	    int row=-1;
	    while(x<n && y>=0){
	       if(arr[x][y]==1){
	           y--;
	           row=x;
	       }
	       else if(arr[x][y]==0){
	           x=x+1;
	       }
	    }
	    return row;
	}

};

// intuition was start at extreme right i=0,j=m-1 (first row last col)
//save an var row to mark your first occurence of 1 in that row ; now till while runs if we find any 1 then to check if its first occurence or not 
// going to right means (more 1's ->> sorted row wise)// so we go to left (j--) prev col to check if there are any 1's before this and save this also in a row var;
// if there is any 0 means 1 will be on right so u inc row wise x=x+1;
// in the end u return row giving u the actual max(no. of 1's in a row wise sorted arr).