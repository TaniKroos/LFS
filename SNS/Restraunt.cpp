#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<set>
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
    vector<pair<int,int> > timings;
    rep(i,n){
        int a ,b;
        cin>>a>>b;
        timings.push_back( { a , 1 } );
        timings.push_back({b,-1});
    }
    sort(timings.begin(),timings.end());
    int c=0;
    int mxi = 0;
    for(int i=0;i<2*n;i++){
        c+=timings[i].second;
        mxi=max(mxi,c);
    }
    cout<<mxi<<endl;
    return 0;
}