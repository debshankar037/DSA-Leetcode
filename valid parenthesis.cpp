bool isValid(string s) {
        stack<char> stack;
        if(s.size()==1)
            return 0;
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                stack.push(s[i]);
            else if(s[i]==')')
            {
                if(!stack.empty()&&stack.top()=='(')
                    stack.pop();
                else return 0;
            }
            else if(s[i]=='}')
            {
                if(!stack.empty()&&stack.top()=='{')
                    stack.pop();
                else return 0;
            }
            else if(s[i]==']')
            {
                if(!stack.empty()&&stack.top()=='[')
                    stack.pop();
                else return 0;
            }
            i++;
        }
        if(stack.empty())
            return 1;
        else return 0;
    }
