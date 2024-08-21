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
    int a ,b;
    cin>>a>>b;
    vector<vector<int> > dp(a+1,vector<int> (b+1,0));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if( i == j) continue;
            dp[i][j] = 1e9;
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j],dp[k][j] + dp[i-k][j] + 1);
            }

            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[i][j-k] +1);
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}