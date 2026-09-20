class Solution {
public:
    int reverseDegree(string s) 
    {
        int ans=0;

        for(int i=0;i<s.size();i++)
        {
            // reversed alphabet ka index nikal rahe hain
            int x=26-(s[i]-'a');

            // string ka 1-indexed position multiply kar rahe hain
            ans+=x*(i+1);
        }

        return ans;
    }
};