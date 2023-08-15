#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        // Idea: Maintain a stack that will contain the most recent opening bracket type at its back/top
            // When a closing bracket is encountered, see if they match or do not
            // If there is a mismatch, then we should immediately return false
        std::stack<char> st;
        int n = s.size();
        if (n % 2 == 1) { return false; } // An odd amount of characters cannot possibly have pairs of brackets
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '{' || c == '[' || c == '(') {
                st.push(c);
                continue;            
            }
            if (st.empty()) { return false; }
            switch (s[i]) {
                case '}':
                    if (st.top() != '{') { return false; }   
                    st.pop();
                    break;
                case ']':
                    if (st.top() != '[') { return false; }   
                    st.pop();
                    break;
                case ')': 
                    if (st.top() != '(') { return false; }   
                    st.pop();
                    break;
            }
        }
        return (st.empty());
    }
};