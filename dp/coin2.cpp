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


int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    vector<int> dp(x+1,0);
    for(int i=0;i<n;i++){
        cin>>coins[i];

    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j-coins[i]>=0){
                dp[j]+=dp[j-coins[i]];
                dp[j]%=MOD;
            }
        }
    }
    cout<<dp[x];

    return 0;
}