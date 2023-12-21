#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    int iVal = nums[0];    // slow ptr
    int jVal = nums[iVal]; // fast ptr
    // locate cycle by treating nums[x] as a pointer to another number in nums
    // (like a linked list)
    while (iVal != jVal) {
      iVal = nums[iVal];
      jVal = nums[nums[jVal]];
    }

    // let them meet up at the beginning of the cycle (find the duplicate
    // number/index)
    iVal = 0; // reset back to start
    while (iVal != jVal) {
      iVal = nums[iVal];
      jVal = nums[jVal]; // progress at normal speed
    }

    return iVal;
  }
};
