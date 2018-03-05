class Solution {
public:
    int longestValidParentheses(string s) {

        if(s.size() == 0 || s.size() == 1)
            return 0;

        stack<int> Stack;
        int* A = new int[s.size()];
        for(int i = 0; i < s.size(); i++)
            A[i] = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                Stack.push(i);
                continue;
            }

            if(s[i] == ')')
            {
                if(Stack.empty())
                {
                    A[i] = -1;
                }
                else
                {
                    int temp = Stack.top();
                    A[temp] = 1;
                    A[i] = 1;
                    Stack.pop();
                    continue;
                }
            }
        }


        while(!Stack.empty())
        {
            int temp = Stack.top();
            A[temp] = -1;
            Stack.pop();
        }


        int count = 0;
        int max_count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(A[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if(count > max_count)
            {
                max_count = count;
            }

        }

        return max_count;

    }
};