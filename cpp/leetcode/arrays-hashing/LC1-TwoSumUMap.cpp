#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
         * Using idea of top solution:
         *  "A more efficient approach is to use a hash table (unordered_map in C++). We can iterate through the array once, and for each element, check if the target minus the current element exists in the hash table. If it does, we have found a valid pair of numbers. If not, we add the current element to the hash table."
        */

        unordered_map<int,int> umap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (umap.find(complement) != umap.end()) {
                int index = umap.at(complement);
                return {i,index};
            } else {
                umap[nums[i]] = i;
            }
        }

        return {};
    }
};