#include <iostream>
#include <vector>

class Solution {
public:
    // Recursive helper function to keep track of recursion tree so far and either append to ans or continue
    void solve(int leftRem, int rightRem, std::string currStr, std::vector<std::string>& ans) {
        if (leftRem == 0 && rightRem == 0) {
            ans.push_back(currStr);
            return;
        }
        if (leftRem == rightRem || rightRem == 0) {
            solve(leftRem-1, rightRem, currStr+"(", ans);
        } else if (leftRem == 0) {
            solve(leftRem, rightRem-1, currStr+")", ans);
        } else {
            // We have two different options in this case, and we need to cover both of them
            solve(leftRem-1, rightRem, currStr+"(", ans);
            solve(leftRem, rightRem-1, currStr+")", ans);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans; 
        solve(n, n, "", ans); // solve will operate on ans and populate it with all valid combinations
        return ans;
    }
};