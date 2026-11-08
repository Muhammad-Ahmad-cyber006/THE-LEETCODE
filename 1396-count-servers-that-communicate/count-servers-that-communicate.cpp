class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> rows(m,0),cols(n,0);

        // Count servers in each row and column
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }    
        int ans=0;

        // Count servers having another server in row or column
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]&&(rows[i]>1||cols[j]>1))
                {
                    ans++;
                }
            }
        }        
        return ans;
    }
};