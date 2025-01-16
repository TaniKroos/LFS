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
        int n;
        cin>>n;
        vector<char> a(n);
        rep(i,n){
            cin>>a[i];
        }
        int c = 0;
        for(int i=0;i<n;i++){
            
            if( i>=2 && a[i]=='.' && a[i-2]==a[i] && a[i-1]==a[i]){
                c = 2;
                break;
            }
           
           if(a[i]=='.'){
            c++;
           }
        }
        cout<<c<<endl;
    }
    return 0;
}