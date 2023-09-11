// LC981: Time Based Key-Value Store
#include <unordered_map>
#include <vector>
#include <iostream>


class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string,int>>> mp;

    TimeMap() {}
    
    void set(std::string key, std::string value, int timestamp) {
        if (mp.find(key) == mp.end()) {
            mp[key] = std::vector<std::pair<std::string, int>>{};
        }
        // Since timestamps are in increasing order, this will maintain ascending sorted order
        mp[key].push_back({value, timestamp});
    }
    
    std::string get(std::string key, int timestamp) {
        std::string res = "";
        std::vector<std::pair<std::string,int>> &vec = mp[key]; 
        // Perform binary search to find timestamp, or smallest value less than timestamp
        int l = 0, r = vec.size() - 1;

        while (l <= r) {
            int mid = l + (r-l)/2;
            if (vec[mid].second <= timestamp) {
                res = vec[mid].first;
                if (vec[mid].second == timestamp) {
                    return res;
                }
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */