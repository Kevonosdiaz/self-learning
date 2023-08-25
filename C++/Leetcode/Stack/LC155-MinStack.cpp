#include <vector>
#include <utility>
#include <algorithm>

class MinStack {
public:
    // If we want to support getMin() in O(1) we need to be able to adjust it in O(1) into some variable for quick access
    // We could use a pair to store the current and min, for every node (this should work but would be less space efficient than some other potential solutions)

    std::vector<std::pair<int,int>> vec;

    MinStack() {}
    
    void push(int val) {
        if (vec.empty()) {
            vec.push_back({val, val});
        } else {
            vec.push_back({val, std::min(val, vec.back().second)});
        }

    }
    
    void pop() {
        vec.pop_back();
    }   
    
    int top() {
        return vec.back().first;
    }
    
    int getMin() {
        return vec.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */