class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) 
    {
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++)
        {
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        string ans;
        int i=0;

        while(i<s.size())
        {
            if(s[i]=='(')
            {
                // bracket ke andar key read karna start kar rahe hain
                i++;

                string key;

                while(s[i]!=')')
                {
                    // key ke characters store kar rahe hain
                    key+=s[i];
                    i++;
                }

                // key ke liye known value checker
                if(mp.find(key)!=mp.end())
                    ans+=mp[key];
                else
                    ans+='?';

                // closing bracket ko skip 
                i++;
            }
            else
            {
                // normal character ko answer me add
                ans+=s[i];
                i++;
            }
        }

        return ans;
    }
};