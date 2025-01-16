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
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        rep(i,n){
            cin>>a[i];
        }
        int c = INT_MIN;
        for(int i=0;i<n;i++){
            if(i==0){
                c = max(c,abs(a[0]-0));
            }
            
            else{
                c = max(c,a[i] - a[i-1]);
            }
        }
  
        c = max(c,2*(k-a[n-1]));
        cout<<c<<endl;
    }
    return 0;
}