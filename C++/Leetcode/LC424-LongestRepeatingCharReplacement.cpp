#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        // Sliding Window Approach
        // Keep counter for number of replaced characters (no need to actually create a new string)
        // Keep pointers for the start and end of a substring

        // Relying on Neetcode solution for this one

        int maxLen = 0;
        int l = 0;
        int n = s.size();

        std::unordered_map<char,int> count;
        int maxf = 0;  // May be wrong max freq for a given window but produces a correct result overall

        for (int r = 0; r < n; r++) {
            count[s[r]]++;
            maxf = std::max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }

            maxLen = std::max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};