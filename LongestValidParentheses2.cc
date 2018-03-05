class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> Stack;
        Stack.push(-1);
        int max_len = 0;

        for(int i = 0; i < s.size(); i++)
        {
            int t = Stack.top();
            if(t != -1 && s[i] == ')' && s[t] == '(')
            {
                Stack.pop();
                max_len = max(max_len, i - Stack.top());
            }
            else
            {
                Stack.push(i);
            }
        }

        return max_len;

    }
};