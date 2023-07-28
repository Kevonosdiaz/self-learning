// LC125 : Valid Palindrome
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    

        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {
            if (!isalnum(s[start])) { start++; continue; }              // Keep going until start is an alnum char
            if (!isalnum(s[end]))   { end--; continue; }                // Keep going until end is an alnum char
            if (tolower(s[start]) != tolower(s[end])) { return false; } // Compare the lower case versions of each
            start++;
            end--;
        }

        return true;
    }
};