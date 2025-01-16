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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%3==0){
            cout<<"Second"<<endl;
        }
        else{
            cout<<"First"<<endl;
        }
        
    }
    return 0;
}