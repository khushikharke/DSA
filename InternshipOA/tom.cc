#include<bits/stdc++.h>

using namespace std;

void fileio(){
    freopen("input.txt","r",stdin);
}
bool isValid(int mid, vector<int> &holes ,int n,int m){
    int cats = 1,sum = 0;
    for(int i=0;i<n;i++){
        sum += holes[i];
        if(sum > mid){
            sum = holes[i];
            cats++;
        }
    }
    return cats == m;
}

void solve(){
    int m,n;
    cin>>m>>n;
    int start = 0, end = 0, ans;
    vector<int> holes(n);
    for(auto &x : holes){
        cin>>x;
        end += x;
        start = max(start, x);
    }

    while(start <= end){
        int mid = (start + end)/2;
        auto isvalid = isValid(mid, holes,n,m);
        cout<<isvalid<<endl;
        if(isvalid){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    cout<<ans<<endl;
}

int main(int argc, char const *argv[])
{
    fileio();
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
