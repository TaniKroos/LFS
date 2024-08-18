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
    int n;
    cin>>n;
    if(n<10){
        cout<<1;
        return 0;
        
    }
    vector<int> dp(n+1,INF);
    dp[0]=INF;
    for(int i=1;i<=9;i++){
        dp[i]=1;
    }

    for(int i=10;i<=n;i++){
        int t=i;
        int r=INT_MAX;
        while(t){
            int s=t%10;
            r=min(r,dp[i-s]);
            t=t/10;
        }
        dp[i]=1+r;
    }
    cout<< dp[n];
    return 0;
}