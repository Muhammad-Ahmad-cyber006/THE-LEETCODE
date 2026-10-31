class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        const int MOD=1e9+7;

        vector<vector<long long>> right(m,vector<long long>(n,0));
        vector<vector<long long>> down(m,vector<long long>(n,0));

        right[0][0]=1;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                long long ways=(right[i][j]+down[i][j])%MOD;

                if(grid[i][j]==0) {
                    if(j+1<n) right[i][j+1]=(right[i][j+1]+ways)%MOD;
                    if(i+1<m) down[i+1][j]=(down[i+1][j]+ways)%MOD;
                }
                else {
                    if(j+1<n) right[i][j+1]=(right[i][j+1]+down[i][j])%MOD;
                    if(i+1<m) down[i+1][j]=(down[i+1][j]+right[i][j])%MOD;
                }
            }
        }

        return (right[m-1][n-1]+down[m-1][n-1])%MOD;
    }
};