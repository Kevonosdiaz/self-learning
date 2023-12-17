#include <unordered_map>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Idea #1 Use a HashMap
            // Ordered Map: Would allow us to traverse first k key-value pairs and get just the values to store in result vector
            // Unordered Map: Faster operations, but we may need to parse more key-value pairs, and maybe sort, so it might not be as fast?
        unordered_map<int,int> mp; // Key is the number, and the value is the occurrences
        vector<int> ans;
        int size = nums.size();
        for (int i = 0; i < size; i++) { mp[nums[i]]++; }

        // But now, how can we sort by value? Solution uses a priority_queue (implemented via Max Heap)

        set<int> st(nums.begin(), nums.end());
        priority_queue<pair<int,int>> pq;

        for (set<int>::iterator iter = st.begin(); iter != st.end(); iter++) {
            pq.push({mp[*iter],*iter}); // Push a pair: Our map is used to push the frequency (accessed via element in nums), alongside the number in nums itself
        }

        while (k--) {
            ans.push_back(pq.top().second); // First in the pair is the frequency, second is the number in nums
            pq.pop(); // Want to regenerate next highest frequency number in the priority queue, so get rid of ones we have stored already
        }

        return ans;
    }
};
