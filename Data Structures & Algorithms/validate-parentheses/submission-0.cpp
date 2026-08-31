class Solution {
public:
    bool isValid(string s) {
        
    stack<char> st;
        
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle closing brackets
            else {
                if (st.empty()) return false;
                
                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};
