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


void D(int node,vector<int> adj[],int par,int d,int& maxD,int& farNode){
    if(d>maxD){
        maxD=d;
        farNode = node;
    }
    for(int i:adj[node]){
        if(i!=par){
            D(i,adj,node,d+1,maxD,farNode);
        }
    }
}

void DD(int node,vector<int> adj[],int par,vector<int>& dis,int d){
    dis[node] = d;
    for(int i:adj[node]){
        if(i!=par){
            DD(i,adj,node,dis,d+1);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int maxD = 0;
    int d = 0;
    int farNode = 1;
    D(1,adj,-1,0,maxD,farNode);
    

    vector<int> disA(n+1,0),disB(n+1,0);
    DD(farNode,adj,-1,disA,0);
    int B = max_element(disA.begin(),disA.end()) - disA.begin();
    DD(B,adj,-1,disB,0);
    for(int i=1;i<=n;i++){
        cout<<max(disA[i],disB[i])<<" ";
    }
    
}