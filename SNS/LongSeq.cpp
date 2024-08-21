#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
#define rep( i,n) for(int i=0;i<n;i++)
int longestUniqueSequence(vector<int>& songs) {
    unordered_set<int> songSet;
    int left = 0, right = 0, maxLength = 0;
    int n = songs.size();
    
    while (right < n) {
        if (songSet.find(songs[right]) == songSet.end()) {
            // If song is unique, add it to the set and expand the window
            songSet.insert(songs[right]);
            right++;
            maxLength = max(maxLength, right - left);
        } else {
            // If song is a duplicate, remove the leftmost song and shrink the window
            songSet.erase(songs[left]);
            left++;
        }
    }
    
    return maxLength;
}

int main() {
    int n;
    cin>>n;
    vector<int> songs(n);
    rep(i,n) cin>>songs[i];
    cout << longestUniqueSequence(songs) << endl;
    return 0;
}
