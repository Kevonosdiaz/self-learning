#include <unordered_set>
#include <iostream>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Idea #1: Slide through array while using a set to keep track of duplicates, adjusting the substring (track using pointers) and map so far as needed when duplicates arise or a new character is found
        std::unordered_set<char> chars;
        int maxLen = 0;
        int n = s.size();
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (chars.find(s[r]) != chars.end()) { 
                chars.erase(s[l]);
                l++; 
            } // Keep moving left ptr until it reaches the dupe
            chars.emplace(s[r]);
            maxLen = std::max(maxLen, r - l + 1);
        }
        return maxLen;    
    }
};