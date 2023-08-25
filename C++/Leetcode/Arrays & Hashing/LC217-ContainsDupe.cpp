#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]]++;
            } else {
                return true;
            }
        }

        return false;

    }
};