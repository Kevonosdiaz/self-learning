#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::stack<int> st;
        std::vector<int> res(n, 0);
        st.push(0); 
        for (int i = 0; i < n; i++) {
            int temp = temperatures[i];
            while (!st.empty() && temp > temperatures[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;

    }
};