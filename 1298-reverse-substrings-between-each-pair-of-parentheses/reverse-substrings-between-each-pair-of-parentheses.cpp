class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<string> st;
        string cur;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                // current string ko stack me store karke new level start 
                st.push(cur);
                cur="";
            }
            else if(s[i]==')')
            {
                // current bracket ke andar wali string reverse 
                reverse(cur.begin(),cur.end());

                // previous level ki string wapas 
                cur=st.top()+cur;
                st.pop();
            }
            else
            {
                // normal character ko current string me add
                cur+=s[i];
            }
        }

        return cur;
    }
};