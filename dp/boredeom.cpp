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


int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> cnt(100001);
    ll mxi = 0;
    rep(i,n){
        cin>>v[i];
        mxi=max(mxi,v[i]);
         cnt[v[i]]++;
    }
   
 
    vector<ll> dp(mxi+1,0);
    dp[0]=0;
    dp[1]=cnt[1];
    for(int i=2;i<=mxi;i++){
        dp[i]=max(dp[i-1],dp[i-2] + cnt[i]*i);
    }
    cout<<dp[mxi];
    return 0;
}