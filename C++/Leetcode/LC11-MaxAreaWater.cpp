// LC11: Container with Most Water

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        using namespace std;
        // Could use min(current height, height[i])
        // Looking for a contiguous subarray of moderate-large length, whose first and last elements are "large"
        // If the first and last elements have a min(i,j) that is large, then the height of our box is large,
        // and with a larger array, our width is large too

        // Idea #1
            // Use a left ptr and right ptr and use their min(height[l], height[r]) to get height of box
            // Use the difference in ptr index to get the width of box
            // It will not be sufficient to advance both pointers simulatenously, since we miss some combinations and   require the _maximum_ area
            // Based on the hint, just adjust the pointer with the lower height (?)

        int max = 0;
        int size = height.size();
        int l = 0;
        int r = size - 1;

        int h; // min(height[l], height[r])
        int w; // r - l;
        int area; // h * w

        while (l < r) {
            h = min(height[l], height[r]);
            w = r - l;
            area = h * w;
            if (area > max) {
                max = area;
            }

            // Adjust ptrs
            if (height[l] < height[r]) {
                l++;
            } else { r--; }

        }

        return max;
    }
};