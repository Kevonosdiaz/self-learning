import java.util.*;

class Solution {
    public boolean isValid(String s) {
        if (s.length() == 0) {
            return true;
        }

        if (s.length() % 2 == 1) {
            return false;
        }

        HashMap<Character, Character> hm = new HashMap<>();
        hm.put('(', ')');
        hm.put('{', '}');
        hm.put('[', ']');

        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (hm.containsKey(c)) {
                stack.push(c);
            } 
            else if (!(stack.empty())){
                char open = stack.peek();
                char close = hm.get(open);
                if (c == close) {
                    stack.pop();
                } else {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        if (!(stack.empty())){
            return false;
        }
        return true;
    }
}
