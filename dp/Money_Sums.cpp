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
    vector<int> v(n);
    long long sum = 0;
    rep(i,n){
        cin>>v[i];
        sum+=v[i];
    }
    vector<vector<long long > > dp(n ,vector<long long> (sum+1 , 0));
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    if(v[0]<=sum) dp[0][v[0]] = 1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum ; j++){
            int nt =  dp[i-1][j];
            int t =0;
            if(v[i] <= j){
                 t = dp[i-1][j-v[i]];
            }
            dp[i][j] = nt || t;
        }
    }
    int c = 0;
    vector<int> ans;
    for(int i=1;i<=sum;i++){
        if(dp[n-1][i]){
            c++;
            ans.push_back(i);
        }
    }
    cout<<c<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}