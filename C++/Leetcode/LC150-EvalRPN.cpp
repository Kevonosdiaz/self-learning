#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        using namespace std;
        stack<string> s;
        int a;
        int b;
        int c;
        string st;
        char ch;

        for (int i = 0; i < tokens.size(); i++) {
            st = tokens[i];
            ch = st[0];
            bool neg = (ch == '-' && st.size() > 1);
            switch(ch) {
                case '+':
                    b = stoi(s.top());
                    s.pop();
                    a = stoi(s.top());
                    s.pop();
                    c = a + b;
                    s.push(to_string(c));
                    break;
                case '-':
                    if (neg) {
                        s.push(tokens[i]);  
                        break;
                    }
                    b = stoi(s.top());
                    s.pop();
                    a = stoi(s.top());
                    s.pop();
                    c = a - b;
                    s.push(to_string(c));
                    break;
                case '*':
                    b = stoi(s.top());
                    s.pop();
                    a = stoi(s.top());
                    s.pop();
                    c = a * b;
                    s.push(to_string(c));
                    break;
                case '/':
                    b = stoi(s.top());
                    s.pop();
                    a = stoi(s.top());
                    s.pop();
                    c = a / b;
                    s.push(to_string(c));
                    break;
                default:
                    s.push(tokens[i]);  
            }
        }
        return stoi(s.top());
    }
};