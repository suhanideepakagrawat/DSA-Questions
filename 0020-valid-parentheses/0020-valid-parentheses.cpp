class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stack1;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                stack1.push(ch);
            } 
            else {
                if (stack1.empty()) return false;
                char topChar = stack1.top();
                if ((ch == ')' && topChar == '(') || 
                (ch == '}' && topChar == '{') || 
                (ch == ']' && topChar == '[')) {
                    stack1.pop(); 
                } else {
                    return false; 
                }
        }
     }
    return stack1.empty();
    }
};