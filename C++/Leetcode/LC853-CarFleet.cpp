#include <vector>
#include <map>
#include <stack>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        // We can use an ordered map (<map>) to sort by position but maintain ordering with speed
        std::map<int, int, std::greater<int>> mp;
        for (int i = 0; i < position.size(); i++) {
            mp[position[i]] = speed[i];
        }

        // Stack to track fleets in order of their arrival timings
        std::stack<float> st;
        for (auto i : mp) {
            float dist = target - i.first;
            float eta = dist/i.second;
            //cout << i.first << ", " << eta << "\n";
            if (st.empty() || eta > st.top()) {
                st.push(eta);
                //cout << "Pushing car with pos of " << i.first << "\n";
            } 
        }

        return st.size();
    }
};