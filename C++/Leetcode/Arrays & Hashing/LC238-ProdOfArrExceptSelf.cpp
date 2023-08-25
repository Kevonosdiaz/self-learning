// 238. Product of Array Except Self
/**
 * A version that is fairly slow (35ms, beats 24.59%; 24mb, beats 49.02%)
 * Keep track of two arrays with the same size as the input vector, which keeps a rolling track of the left and right products (relative to nums[i])
 * A for loop (executing n-1 times) initializes the entries of leftP and rightP (the arrays), where the first and last entry for leftP and rightP respectively is 1 (so the product is unaffected)
 * Another for loop (executing n times) replaces nums[i] with leftP[i] * right[i], generating the result vector<int> in-place, although external arrays are used
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int leftP[size];
        int rightP[size];

        leftP[0] = 1;
        rightP[size-1] = 1;
        int j;
        for (int i = size-2; i >= 0; i--) {
            j = size - i - 1;
            rightP[i] =  rightP[i+1] * nums[i+1];
            leftP[j] = leftP[j-1] * nums[j-1];
        }

        for (int i = 0; i < size; i++) {
            nums[i] = leftP[i] * rightP[i];
        }
        return nums;
    }
};