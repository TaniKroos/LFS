#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// Include other necessary headers...

using namespace std;

#include <climits>
#define MOD 1000000007
#define ll long long
#define rep( i,n) for(int i=0;i<n;i++)

// Define an infinite value for initial comparison
const int INF = INT_MAX;

int main(){
    int n;
    int w;
    cin>>n>>w;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }  
    rep(i,n){
        cin>>b[i];
    } 
    vector<vector<int> > dp(n,vector<int> (w+1));
    for(int i=a[0];i<=w;i++){
        dp[0][i]=b[0];
    }

    for(int i=1;i<n;i++){
        for( int j=0;j<=w;j++){
            int take=INT_MIN;
            int not_take=dp[i-1][j];
            if(j>=a[i]) take=b[i]+ dp[i-1][j-a[i]];
            dp[i][j]=max(take,not_take);
        }
    }
    cout<<dp[n-1][w];
    return 0;
}