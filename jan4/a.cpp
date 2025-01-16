#include <iostream>
#include <vector>
using namespace std;

// you have to implement the mostInfluentialUser() only
int mostInfluentialUser(vector<int> influenceScore) {
    int sc= 0 ;
    int ans = -1;
    for(int i=0;i<influenceScore.size();i++){
        if(influenceScore[i]>sc){
            sc = influenceScore[i];
            ans = i;
        }
    }
    return ans;
}

int main() {
    // Read input
    int n, m;
    cin >> n >> m;
    vector<int> influenceScore(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u != v) { 
            influenceScore[v]++;
        }
    }
    // please don't change the main function
    for(int i=0;i<n;i++){
        cout<<influenceScore[i]<<" ";
    }
    cout<<endl;
    cout << mostInfluentialUser(influenceScore);
    return 0;
}       