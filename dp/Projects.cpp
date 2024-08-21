#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// Include other necessary headers...

using namespace std;

#include <climits>
#define MOD 1000000007 
#define ll long long


// Define an infinite value for initial comparison
const int INF = INT_MAX;
#define rep( i,n) for(int i=0;i<n;i++)


struct job{
    /* data */
    ll start ,  end , profit ;
};
bool compare(job j1 , job j2){
    return j1.end < j2.end;
}


int binary_search(ll a,int start,int end, job* arr){
    int ans = -1;
    while (start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid].end < a){
            ans = max(ans , mid);
            start = mid +1;
        }else{
            end = mid - 1;
        }

    }
    return ans;   
    
}

int main(){
    int n;
    cin>>n;
    job *arr = new job[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start;
        cin>>arr[i].end;
        cin>>arr[i].profit;
    }
    sort(arr, arr+n,compare);
    vector<ll> dp(n,0);
    dp[0]=arr[0].profit;
    for(int i=1;i<n;i++){
        ll  nt = dp[i-1];
        ll t = arr[i].profit;
        int ind = binary_search(arr[i].start , 0 , i-1 , arr);
        if(ind != -1){
            t += dp[ind];
        }
        dp[i] = max(t,nt);

    }
    cout<<dp[n-1]<<endl;

    return 0;
}