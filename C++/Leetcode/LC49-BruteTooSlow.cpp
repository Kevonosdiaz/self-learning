#include <vector>
#include <iostream>
#include <map> // Consider using an unordered_map instead, if equality is quick to check still
using namespace std;

class Solution {
public:
    /*
     * Idea #1: Brute force approach:
     *  Iterate through the array, and call isAnagram between the current element and every other element in the array
     *  If isAnagram returns true, then add it to a temporary array (and we could consider removing it from the input arr)
     *  Continue for rest of array elements, then add the current element to the temp array, and append the array to result
     *  Repeat for rest of array, and consider removal (?) of elements that have been checked, or confirmed as anagrams

     * Idea #2: Generate char maps for all strings, then compare (simply extending Valid Anagram solution?)
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++) {
            vector<string> subResult;
            vector<int> erasureList;
            for (int j = i + 1; j < strs.size(); j++) {
                if (isAnagram(strs[i],strs[j])) {
                    subResult.insert(subResult.end(), strs[j]);
                    erasureList.insert(erasureList.end(), j);
                    // strs.erase(strs.begin() + j);
                }
            }
            subResult.insert(subResult.end(), strs[i]);
            result.insert(result.end(), subResult);
            
            // Handle erasure of elements
            for (int j = 0; j < erasureList.size(); j++) {
                strs.erase(strs.begin() + erasureList[j] - j);
            }
        }
        return result;
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }

        map<char, int> sMap, tMap;

        for (auto i : s) {
           sMap[i]++;
        }

        for (auto i : t) {
            tMap[i]++;
        }

        return (sMap == tMap);
    }
};