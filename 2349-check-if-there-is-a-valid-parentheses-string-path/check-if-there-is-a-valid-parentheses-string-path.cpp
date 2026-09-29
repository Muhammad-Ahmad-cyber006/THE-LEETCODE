class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();

        // path ki total length odd hai to valid string nahi banega
        if((m+n-1)%2)
            return false;

        // dp[i][j][b] bata raha hai ke balance b ke saath cell tak pahunch sakte hain
        vector<vector<vector<bool>>> dp( m,vector<vector<bool>>(n,vector<bool>(m+n,false)));

        // starting cell '(' nahi hai to valid path possible nahi hai
        if(grid[0][0]==')')
            return false;

        dp[0][0][1]=true;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                    continue;

                // current cell ke bracket ke according balance change
                int change=(grid[i][j]=='(')?1:-1;

                for(int b=0;b<m+n;b++)
                {
                    int prev=b-change;

                    // previous balance valid range me check 
                    if(prev<0||prev>=m+n)
                        continue;

                    // upar se ya left se current balance tak 
                    if((i>0&&dp[i-1][j][prev])||(j>0&&dp[i][j-1][prev]))
                    {
                        // current bracket add karke balance store
                        dp[i][j][b]=true;
                    }
                }
            }
        }

        // end par balance 0 hona valid parentheses string 
        return dp[m-1][n-1][0];
    }
};