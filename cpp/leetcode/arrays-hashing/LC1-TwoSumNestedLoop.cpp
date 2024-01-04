#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1 : Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* 
        Idea #1: Iterate through vector and check sum between other members of the vector
        - Ignore the first i entries in the array, since they did not produce the solution
        - i loop keeps track of the first number, while the j loop checks every index > i 
        for a potential solution when added to i
        - Should be better than the brute force answer, but still > O(n) (it's n^2)
        */
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i,j}; 
                }
            }
        }

        return {-1,-1};
    }
};