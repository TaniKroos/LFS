#include<iostream>
#include<vector>
using namespace std;

// int main() {
//   int n;
//   cin >> n;
//   vector<int> x(n);
//   vector<long long> sum (n+1);
//   for (int&v : x) {
//     cin >> v;
    
//   }
//   long long c = 0;
//   for(int i=0;i<n;i++){
//     c+=x[i];
//     sum[i+1]=c;

//   }

//   vector<vector<long long> > dp(n,vector<long long>(n));
//   for (int l = n-1; l >= 0; l--) {
//     for (int r = l; r < n; r++) {
//       if (l == r) {
// 	dp[l][r] = x[l];
//       } else {
//                 long long leftSum = sum[r + 1] - sum[l]; // sum of elements from l to r
//                 dp[l][r] = max(leftSum - dp[l + 1][r], leftSum - dp[l][r - 1]);
//             }
//     }
//   }
//   cout << dp[0][n-1] << endl;
// }
#define rep( i,n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  int sum = 0;
  vector<int> v(n);
  vector<vector<int> > dp(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    cin>>v[i];
    dp[i][i] = v[i];
    sum+=v[i];
  }

 
  for(int i=n-1;i>=0;i--){
    for(int j=i+1;j<n;j++){
      
      dp[i][j] = max(v[i] - dp[i+1][j],v[j]- dp[i][j-1]);
    }
  }
  cout<<(sum + dp[0][n-1])/2<<endl;
  
}