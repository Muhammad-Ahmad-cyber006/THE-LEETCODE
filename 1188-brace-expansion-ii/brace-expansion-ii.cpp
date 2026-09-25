class Solution {
public:
    set<string> parseSequence(string &s,int &i)
    {
        // current sequence ke possible words store kar rahe hain
        set<string> cur;
        cur.insert("");

        while(i<s.size()&&s[i]!=','&&s[i]!='}')
        {
            set<string> part;

            if(s[i]=='{')
            {
                // braces ke andar wali expression parse kar rahe hain
                i++;
                part=parseExpression(s,i);

                // closing brace ko skip kar rahe hain
                i++;
            }
            else
            {
                // current letter ko single word bana rahe hain
                part.insert(string(1,s[i]));
                i++;
            }

            set<string> temp;

            // current words aur new words ko concatenate kar rahe hain
            for(set<string>::iterator a=cur.begin();a!=cur.end();a++)
            {
                for(set<string>::iterator b=part.begin();b!=part.end();b++)
                {
                    // dono words ko join karke store kar rahe hain
                    temp.insert(*a+*b);
                }
            }

            // naye words ko current sequence me store kar rahe hain
            cur=temp;
        }

        return cur;
    }

    set<string> parseExpression(string &s,int &i)
    {
        set<string> ans;

        while(i<s.size()&&s[i]!='}')
        {
            // ek complete sequence parse kar rahe hain
            set<string> part=parseSequence(s,i);

            // sequence ke saare words union me add kar rahe hain
            for(set<string>::iterator it=part.begin();it!=part.end();it++)
                ans.insert(*it);

            if(i<s.size()&&s[i]==',')
            {
                // comma ko skip karke next alternative parse kar rahe hain
                i++;
            }
        }

        return ans;
    }

    vector<string> braceExpansionII(string expression) 
    {
        int i=0;

        // complete expression ko parse kar rahe hain
        set<string> ans=parseExpression(expression,i);

        // sorted set ko vector me convert kar rahe hain
        return vector<string>(ans.begin(),ans.end());
    }
};