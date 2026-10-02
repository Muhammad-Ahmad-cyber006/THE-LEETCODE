class Solution {
public:
    void solve(int n,int open,int close,string curr,vector<string>& ans)
    {
        // n opening brackets use kar chuke hain 
        if(open==n&&close==n)
        {
            // complete valid string answer me store
            ans.push_back(curr);
            return;
        }

        // abhi opening brackets available hain to ( add 
        if(open<n)
            solve(n,open+1,close,curr+"(",ans);

        // closing bracket tabhi laga rahe hain jab balance positive 
        if(close<open)
            solve(n,open,close+1,curr+")",ans);
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;

        // empty string se backtracking start kar 
        solve(n,0,0,"",ans);

        return ans;
    }
};