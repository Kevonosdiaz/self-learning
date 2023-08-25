#include <limits.h>
#include <vector>
#include <stack>
#include <cstring>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        // O(n) time and space solution using stack and 2 arrays

        // Initialize two stacks that will be used to find smallest values to the left and right of heights[i]
        std::stack<int> left;
        std::stack<int> right;

        int n = heights.size();

        // Store smallest value to the left and right of the ith element, where -1 indicates the value DNE
        int leftSmallest[n];
        int rightSmallest[n];
        std::memset(leftSmallest, -1, sizeof(leftSmallest));
        std::memset(rightSmallest, -1, sizeof(rightSmallest));

        // Populate the above two arrays
        for (int l = 0; l < n; l++) {
            int r = (n - 1) - l;     // Index starting from the right which will decrement when l++
            while (!left.empty() && heights[l] <= heights[left.top()]) {
                left.pop();
            }

            while (!right.empty() && heights[r] <= heights[right.top()]) {
                right.pop();
            }

            if (!left.empty()) {
                leftSmallest[l] = left.top();
            } 
            // else {
            //     leftSmallest[l] = l-1;
            // }

            if (!right.empty()) {
                rightSmallest[r] = right.top();
            } 
            // else {
            //     rightSmallest[r] = r+1;
            // }

            left.push(l);
            right.push(r);
        }

        int res = INT_MIN;

        // Loop through heights and calculate area 
        for (int i = 0; i < n; i++) {
            if (rightSmallest[i] == -1) {
                rightSmallest[i] = n;
            }
            int area = (rightSmallest[i] - leftSmallest[i] - 1) * heights[i];
            //cout << rightSmallest[i] << ", " << leftSmallest[i] << ", " << heights[i] << "\n"; 
            res = std::max(area, res);
        }

        return res;
    }
};