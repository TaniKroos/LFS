#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> height(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        // Update the height of the histogram
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '1') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        // Calculate the maximum area for the updated histogram
        maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
}

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    heights.push_back(0);
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        s.push(i);
    }

    heights.pop_back();
    return maxArea;
}
