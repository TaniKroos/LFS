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
    string a,b;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // a[i]==b[j]
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
    }
    cout<<dp[n][m];
}