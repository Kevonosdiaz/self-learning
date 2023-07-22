#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /*
     * Using the explanation of the solution from https://leetcode.com/problems/group-anagrams/solutions/3687735/beats-100-c-java-python-beginner-friendly/
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            mp[word];
            mp[word].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto i : mp) {
            ans.push_back(i.second); // Push the vector of strings for each key into the result vector
        }
    
        return ans;
    }
};