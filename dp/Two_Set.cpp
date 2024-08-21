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
    int sum = n*(n+1)/2;
    if(sum&1){
        cout<<0;
        return 0;
    }
    long long mod = 1e9+7;
    long long dSum = sum/2;
    vector<vector<long long> > dp(n+1,vector<long long>(dSum+1 , 0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=dSum;j++){
            int nt = dp[i-1][j];
            int t = 0;
            if(i<=j){
                t = dp[i-1][j-i];
            }
            dp[i][j]= (t+nt)%mod;
        }
    }
    cout<<dp[n][dSum];


    return 0;
}