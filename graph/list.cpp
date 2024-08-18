#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfSmallestSubstringFromStart(const std::string& str) {
    // Create a frequency map of characters in the original string
    std::unordered_map<char, int> charCount;
    for (char ch : str) {
        charCount[ch]++;
    }
    
    // Create a map to keep track of characters in the current substring
    std::unordered_map<char, int> currentCount;
    int uniqueChars = charCount.size();
    int start = 0, end = 0;
    int minLength = str.length();
    int currentUniqueCount = 0;
    
    while (end < str.length()) {
        // Include the current character in the window
        char endChar = str[end];
        currentCount[endChar]++;
        if (currentCount[endChar] == charCount[endChar]) {
            currentUniqueCount++;
        }
        
        // If the current window contains all unique characters of the original string
        while (currentUniqueCount == uniqueChars) {
            minLength = std::min(minLength, end - start + 1);
            
            // Try to shrink the window from the left
            char startChar = str[start];
            currentCount[startChar]--;
            if (currentCount[startChar] < charCount[startChar]) {
                currentUniqueCount--;
            }
            start++;
        }
        
        end++;
    }
    
    return minLength;
}

int main() {
    std::string str;
    std::cout << "Enter the string: ";
    std::cin >> str;
    
    int result = lengthOfSmallestSubstringFromStart(str);
    
    std::cout << "The length of the smallest substring whose anagrams can be concatenated to form the string is: " << result << std::endl;
    
    return 0;
}
