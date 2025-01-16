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
        int n,m;
        cin >> n >> m;
        string a,b;
        cin >> a >> b;
        int ans = 0;
        int i;
        for(i=0;i<=5;i++){
            if(a.find(b)!=string::npos){
                ans = i;
                break;
            }
            a+=a;
        }
        if(i>5){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}