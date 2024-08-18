#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    vector<int> n(t);
    int max_n = 0;
    
    for (int i = 0; i < t; i++) {
        cin >> n[i];
        if (n[i] > max_n) {
            max_n = n[i];
        }
    }
    
    vector<long long> dp1(max_n + 1), dp2(max_n + 1);
    dp1[1] = 1;
    dp2[1] = 1;

    for (int i = 2; i <= max_n; i++) {
        dp1[i] = (dp1[i-1] + dp2[i-1]) % MOD;
        dp2[i] = dp1[i-1] % MOD;
    }
    
    for (int i = 0; i < t; i++) {
        cout << (dp1[n[i]] + dp2[n[i]]) % MOD << endl;
    }

    return 0;
}