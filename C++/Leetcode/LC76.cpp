// LC76: Minimum Window Substring

/*
Planning:
As we slide through the string, how can we decide when to adjust the left and right pointers?
The left pointer cannot lag behind too much or else we risk never getting the minimum value.

Idea #1:  We check if (s[l] == s[r] && winCount[s[l] > winCount[s[r]]) and can advance then

*/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    // string minWindow(string s, string t) {
    //     int n = t.size();
    //     int m = s.size();
    //     if (n > m) { return ""; } // Cannot possibly have a substring larger than itself
    //     unordered_map<char, int> tCount;
    //     unordered_map<char, int> winCount;
    //     unordered_set<string> results;
    //     // We can start with a window of size t.size(), then advance through.
    //     // If the start of the window does not belong to t, then we can safely shift the window.
    //     // We will need to slide through the entire string s OR find a size t.size() window to return

    //     // Start window for first n-1 elements, and populate tCount's umap
    //     for (int i = 0; i < n; i++) {
    //         tCount[t[i]]++;
    //         winCount[s[i]]++;
    //     }
    //     int matches = 0;
    //     for (auto i : tCount) {
    //         if (winCount.find(i.first) == winCount.end()) { break; } 
    //         if (i.second <= winCount[i.first]) {
    //             matches += i.second;
    //         }
    //     }
    //     if (matches == n) { results.emplace(s.substr(0, n)); }

    //     int l = 0;
    //     for (int r = n; r < m; r++) {
    //         winCount[s[r]]++; // Since we are on a new right ptr
    //         while((tCount.find(s[l]) == tCount.end() || winCount[s[l]] > tCount[s[l]]) && l <= r) {
    //             winCount[s[l]]--;
    //             l++;                
    //         }
    //         matches = 0;
    //         for (auto i : tCount) {
    //             if (winCount.find(i.first) == winCount.end()) { break; } 
    //             if (i.second <= winCount[i.first]) {
    //                 matches += i.second;
    //             }
    //         }
    //         if (matches == n) { results.emplace(s.substr(l, r - l + 1)); }
    //     }
    //     string res;
    //     if (results.empty()) { 
    //         res = "";
    //     } else {
    //         unordered_set<string>::iterator it;
    //         int min = 100000;
    //         for (it = results.begin(); it != results.end(); ++it) {
    //             if (it->size() < min) { 
    //                 min = it->size(); 
    //                 res = *it;
    //             }
                
    //         }
    //     }
    //     return res;
    // }

    // // Check whether the values in winMap match or exceed the values in tMap, for every key in tMap
    // bool cmpMap(unordered_map<char,int> tMap, unordered_map<char,int> winMap, int tSize) {
    //     int count = 0;
    //     for (auto i : tMap) {
    //         if (winMap.find(i.first) == winMap.end()) { return false; } // If winMap lacks a certain key
    //         if (i.second <= winMap[i.first]) {
    //             count += i.second;
    //         }
    //     }
    //     return (count == tSize);
    // }
    string minWindow(string s, string t) {
        string result;
        if(s.empty() || t.empty()){
            return result;
        }
        unordered_map<char, int> map;
        unordered_map<char, int> window;
        for(int i = 0; i < t.length(); i++){
            map[t[i]]++;
        }
        int minLength = INT_MAX;
        int leterCounter = 0;
        for(int l = 0, r = 0; r < s.length(); r++){
            char c = s[r];
            if(map.find(c) != map.end()){
                window[c]++;
                if(window[c] <= map[c]){
                    leterCounter++;
                }
            }
            if(leterCounter >= t.length()){
                while(map.find(s[l]) == map.end() || window[s[l]] > map[s[l]]){
                    window[s[l]]--;
                    l++;
                }
                if(r - l + 1 < minLength){
                    minLength = r - l + 1;
                    result = s.substr(l, minLength);
                }
            }
        }
        return result;
    }
};