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
        vector<int> arr(n);
        map<int,int> st;
        rep(i, n) {
            cin >> arr[i];
            st[arr[i]]++;
        }
        if(st.size()>2)cout<<"No"<<endl;
        else {
            auto it = st.begin();
            auto it2 = --st.end();
            if(abs(it->second - it2->second)>1){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}