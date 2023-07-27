// LC128 - Longest Consecutive Sequence

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
         * What data structures can we use for O(n) or better (O(log(n)) or O(1))
         * 1) Priority Queue (log(n)?) * Iteration (n) = nlogn, so would not work
         * 2) Map/UnorderedMap (n or logn?)
         * 3) Set (logn)
            - Use a set to track all 
         * 4) Array/Vector (n or 1)
         * 5) Stack/Queue (doesn't seem to fit here at all)
         * Sorting does not appear to be a viable option?
        */

        int maxLen = 0;

        // Initialize our set
        unordered_set<int> s(nums.begin(), nums.end());

        int n = nums.size();

        // Iterate through array while referencing our set for sequences
        for (int i = 0; i < n; i++) {
            if (s.find(nums[i]-1) == s.end()) { // Case where there is no sequence predecessor
                int length = 0;
                int current = nums[i];
                while (s.find(current) != s.end()) {
                    length++;
                    current++;
                }
                maxLen = max(maxLen,length);
            }
        }

        return maxLen;
        
    }
};