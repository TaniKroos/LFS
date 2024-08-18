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
class DS {
    vector<int> rank;
    vector<int> par,size;
    public: 
        DS(int n){
            rank.resize(n+1,0);
            par.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<n;i++){
                par[i]=i;
                
            }
        }
        int findUPar(int node){
            if(node == par[node]) return node;
            return par[node]=findUPar(par[node]);
        }

        void UninonRank(int a,int b){
            int pa = findUPar(a);
            int pb = findUPar(b);
            if(pa == pb){
                return;
            }
            if(rank[pa]<rank[pb]){
                par[pa]=pb;
            }
            else if(rank[pa]>rank[pb]){
                par[pb]=pa;
            }
            else{
                par[pa]=pb;
                rank[pb]++;
            }
        }
        void UninonSize(int a,int b){
            int pa = findUPar(a);
            int pb = findUPar(b);
            if(pa == pb){
                return;
            }
            if(size[pa]<size[pb]){
                par[pa]=pb;
                size[pb]+=size[pa];
            }
            else{
                par[pb]=pa;
                size[pa]+=size[pb];
            }
        }




};

int main(){
    DS ds(7);
    ds.UninonSize(1, 2); 
    ds.UninonSize(2, 3); 
    ds.UninonSize(4, 5); 
    ds.UninonSize(6, 7); 
    ds.UninonSize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.UninonSize(3, 7); 
    

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}