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
    int mxi = 0;
    rep(i,n) {
        cin>>v[i];
        sum+=v[i];
        mxi=max(mxi,v[i]);
    }
    sum-=mxi;
    if(mxi>sum){
        cout<<2*mxi<<endl;
    }else{
        cout<<sum+mxi<<endl;
    }
    return 0;
}