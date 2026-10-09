#include <limits>
#include <sstream>
#include <vector>

vector<int> processCouponStackOperations(vector<string> operations)
{
    // st tracks stack state
    // mins[i] is minimum when stack had i elems
    std::vector<int> st{};
    std::vector<int> mins(operations.size(), std::numeric_limits<int>::max());
    std::vector<int> res{};
    for(const auto& op : operations)
    {
        if(op == "top")
        {
            res.push_back(st.back());
        }
        else if(op == "getMin")
        {
            res.push_back(mins[st.size()]);
        }
        else if(op == "pop")
        {
            st.pop_back();
        }
        else
        {
            std::string        tmp;
            int                val = 0;
            std::istringstream s(op);
            s >> tmp >> val;
            st.push_back(val);
            auto n  = st.size();
            mins[n] = std::min(mins[n - 1], val);
        }
    }
    return res;
}
