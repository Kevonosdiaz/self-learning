#include <iostream>
#include <map> // Consider using an unordered_map instead, if equality is quick to check still
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // We could initially check for length equality to speed up the average computation
        if (s.size() != t.size()) {
            return false;
        }

        // If the lengths match, then we need to ensure whether or not t is an anagram of s
        // Idea #1: Store the number of occurrences of each character (maybe HashMap), and check if each is the same
        map<char, int> sMap, tMap;
        for (int i = 0; i < s.size(); i++) {
            if (sMap.count(s[i])) {
                sMap[s[i]]++;
            } else {
                sMap[s[i]] = 0;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (tMap.count(t[i])) {
                tMap[t[i]]++;
            } else {
                tMap[t[i]] = 0;
            }
        }

        return (sMap == tMap);
    }
};