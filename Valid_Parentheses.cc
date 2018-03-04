class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                mystack.push(s[i]);
            }

            else if(s[i] == ')'){
                if(mystack.size() == 0){
                    return false;
                }
                char counter_part = mystack.top();
                mystack.pop();

                if(counter_part != '('){
                    return false;
                }
            }

            else if(s[i] == '}'){
                if(mystack.size() == 0){
                    return false;
                }
                char counter_part = mystack.top();
                mystack.pop();

                if(counter_part != '{'){
                    return false;
                }
            }
            else if(s[i] == ']'){
                if(mystack.size() == 0){
                    return false;
                }
                char counter_part = mystack.top();
                mystack.pop();

                if(counter_part != '['){
                    return false;
                }
            }
        }

        if(mystack.size() != 0){
            return false;
        }

        return true;
    }
};