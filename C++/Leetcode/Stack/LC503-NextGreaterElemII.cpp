#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        std::stack<int> st;
        std::vector<int>res(n,-1);

        // To combat a circular array we can loop through twice, using i%n to hit every index twice
        for (int i = 2*n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i%n] >= st.top()) {
                st.pop();
            }

            if (!st.empty() && i < n) {
                res[i] = st.top();
            }

            st.push(nums[i%n]);
        }

        return res;
    }
};