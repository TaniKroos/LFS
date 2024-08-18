#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// Include other necessary headers...

using namespace std;

#include <climits>
#define MOD 1000000007



// Define an infinite value for initial comparison
const int INF = INT_MAX;

// Memoization array
vector<int> memo;

// Function to find the minimum number of coins needed for amount `x`
int minCoins(int x, const vector<int> coins,vector<int>& tab) {
   if(x<0) return 0;
   if(x==0) return 1;
   if(tab[x]!=-1) return tab[x];
   tab[x]=0;
   for(int i=0;i<coins.size();i++){
    tab[x]+=minCoins(x-coins[i],coins,tab)%MOD;
   }
   return tab[x]%MOD;

}

int main() {
    // Example coin denominations
       int n;
    cin >> n;
    int x;
    cin>>x;
    
    vector<int> a;
    for(int i=0;i<n;i++){
        int f;
        cin>>f;
        a.push_back(f);
    }
    vector<int> dp(x+1);
    vector<int> tab(x+1,-1);
    //minCoins(x,a,tab);
    
    dp[0]=1;
    
    // for(int i=1;i<=x;i++){
    //     for(int j=0;j<n;j++){
    //         if(i-a[j]>=0){
    //             dp[i]+=dp[i-a[j]];
    //             dp[i]%=MOD;
    //         }
    //     }
        
    // }
    //cout<<dp[x]<<endl;
    cout<<minCoins(x,a,tab)<<endl;
    return 0;
}
