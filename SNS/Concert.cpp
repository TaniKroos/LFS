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
    int n,m;
    cin>>n>>m;
    vector<int> ticketPrice(n),price(m);
    set<pair<int,int> > st;
    rep(i,n){
        cin>>ticketPrice[i];
        st.insert( { ticketPrice[i],i });
    }
    rep(i,m){
        cin>>price[i];
    }
    for(int i=0;i<m;i++){
        auto it = st.lower_bound({price[i]+1,0});
        if(it == st.begin()){
            cout<<-1<<" ";
        }else{
            it--;
            cout<<(*it).first<<" ";
            st.erase(it);
        }

    }
   
    return 0;

}