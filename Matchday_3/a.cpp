#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// Include other necessary headers...

using namespace std;

#include <climits>
#define MOD 1000000007
#define ll long long

using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int max_operations(int l, int r) {
    int count = 0;
    
    for (int i = l; i <= r - 2; i++) {

        if (gcd(i, i + 1) == 1 && gcd(i + 1, i + 2) == 1 && gcd(i, i + 2) == 1) {
            count++;
            i += 2; 
        }
    }
    
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin >> l >> r;
    
        cout << max_operations(l, r) << endl;

    }
   
    
    return 0;
}
