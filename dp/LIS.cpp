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
    vector<int> ans;
    rep(i,n){
        cin>>v[i];
        auto it = lower_bound(ans.begin(),ans.end(),v[i]);
        if(it == ans.end()){
            ans.push_back(v[i]);
        }else{
            *it = v[i];
        }
    }
    
   
    cout<<ans.size();
    return 0;
}