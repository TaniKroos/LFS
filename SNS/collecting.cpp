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
    vector<int> v(n+1);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v[a]=i;
    }
    int cnt = 1;
    for(int i=2;i<=n;i++){
        if(v[i]<v[i-1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}