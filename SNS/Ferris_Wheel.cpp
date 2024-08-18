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
    int a,b;
    cin>>a>>b;
    vector<int> children(a);
    rep(i,a){
        cin>>children[i];
    }
    sort(children.begin(),children.end());
    int l  = 0;
    int r = a-1;
    int cnt =0;
    while(l<=r){
        if(children[l]+children[r]<=b){
            cnt++;
            l++;
            r--;
        }
        else{
            r--;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}