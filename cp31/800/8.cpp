#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<map>
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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> a(n);
        bool b = false;
        rep(i,n){
            cin >> a[i];
            if(a[i] == k) b = true;
        }
        if(b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}