#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<long long> sum (n+1);
  for (int&v : x) {
    cin >> v;
    
  }
  long long c = 0;
  for(int i=0;i<n;i++){
    c+=x[i];
    sum[i+1]=c;

  }

  vector<vector<long long> > dp(n,vector<long long>(n));
  for (int l = n-1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r) {
	dp[l][r] = x[l];
      } else {
                long long leftSum = sum[r + 1] - sum[l]; // sum of elements from l to r
                dp[l][r] = max(leftSum - dp[l + 1][r], leftSum - dp[l][r - 1]);
            }
    }
  }
  cout << dp[0][n-1] << endl;
}