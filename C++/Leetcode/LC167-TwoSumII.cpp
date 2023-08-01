#include <vector>

class Solution {
public:
    // Constant Extra Space -> No external hashmap with non-constant amount of keys

    // We should take advantage of how the array is sorted (A left ptr will contain a smaller number, while a right ptr will be larger)
    // so we can adjust our pointers accordingly until they fit the target
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int lp = 0;
        int rp = numbers.size() - 1;
        int sum = numbers[lp] + numbers[rp];

        while (sum != target) {
            if (sum > target) { rp--; }
            else { lp++; }
            sum = numbers[lp] + numbers[rp];
        }

        std::vector<int> res{lp+1,rp+1};
        return res;

    }
};