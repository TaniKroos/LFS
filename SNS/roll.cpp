#include <iostream>
#include <vector>
#include <string>

using namespace std;

string roll_string(string s, vector<int>& roll) {
    int n = s.length();
    vector<int> roll_count(n + 1, 0);
    
    // Mark the rolling operations in roll_count
    for (int i = 0; i < roll.size(); i++) {
        roll_count[0] += 1;
        if (roll[i] < n) {
            roll_count[roll[i]] -= 1;
        }
    }
    
    // Convert roll_count to a prefix sum array
    for (int i = 1; i < n; i++) {
        roll_count[i] += roll_count[i - 1];
    }
    
    // Apply the rolling to the string
    for (int i = 0; i < n; i++) {
        int rolls = roll_count[i];
        s[i] = ((s[i] - 'a' + rolls) % 26) + 'a';
    }
    
    return s;
}

int main() {
    string s = "bca";
    vector<int> roll ;
    for(int i=0;i<4;i++){
        int a;
        cin>>a;
        roll.push_back(a);
    }
    
    string result = roll_string(s, roll);
    cout << result << endl;  // Output should be "eeb"
    
    return 0;
}
