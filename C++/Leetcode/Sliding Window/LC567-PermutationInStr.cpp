// LC567 - Permutation In String

#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
      // Idea 1: Store all permutations of s1 in a set, and then slide a window across s2, with window size based on s1
      // Idea 2: To avoid factorial time complexity, instead store the characters in s1, so that the order/permutation would not matter

        int len = s1.size();
        if (len > s2.size()) { return false; }

        std::unordered_map<char,int> count;
        std::unordered_map<char,int> runningCount;
        int matches = 0;
        
        for (int i = 0; i < len; i++) { 
            count[s1[i]]++; 
            runningCount[s2[i]]++;
        } 

        for (auto i : count) {
                if (i.second != runningCount[i.first]) { break; }
                matches += i.second;
            }
        if (matches == len) { return true; } 

        for (int i = len; i < s2.size(); i++) {
            runningCount[s2[i-len]]--; // Move left-side of window forward
            runningCount[s2[i]]++;     // Move right-side of window forward
            matches = 0;
            for (auto i : count) {
                if (i.second != runningCount[i.first]) { break; }
                matches += i.second;
            }
            if (matches == len) { return true; } 
        }

        return false;
    }
};