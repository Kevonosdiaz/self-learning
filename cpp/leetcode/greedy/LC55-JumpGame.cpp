// LC55 - Jump Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n == 0) return true;
        int reach = 0;
        for (int i = 0; i <= reach; i++) {
            reach = max(reach, i + nums[i]);
            if (reach >= n) return true;
        }
        return false;
    }
};
