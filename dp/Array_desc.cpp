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
    
    ll n,m;
    cin>>n>>m;

    vector<int> array(n);
    rep(i,n){
        cin>>array[i];
    }
    vector<vector<int> > dp(n, vector<int>(m + 1, 0));

    // Initialize the first row of dp table
    if (array[0] == 0) {
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][array[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (array[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j > 1) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                }
                if (j < m) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                }
            }
        } else {
            int j = array[i];
            dp[i][j] = dp[i-1][j];
            if (j > 1) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
            if (j < m) {
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }

    int result = 0;
    for (int j = 1; j <= m; ++j) {
        result = (result + dp[n-1][j]) % MOD;
    }
    cout<<result;
    return 0;
}


/*

   
        [ 3 0 4 0 6 ]

        [ 3 4 0 ] 0 ->{3, 5 ,4 }




*/