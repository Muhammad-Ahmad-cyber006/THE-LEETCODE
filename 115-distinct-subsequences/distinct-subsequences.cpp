class Solution {
public:
    vector<vector<int>>dp;
    int numDistinct(string s, string t) 
    {

        int n=s.size();
        int m=t.size();
        int i=0;
        int j=0;
        dp.resize(n,vector<int>(m,-1));
        return choices(s,t,n,m,i,j);
        
    }

    int choices(string s,string t,int n,int m,int i,int j)
    {
        //base case
        if(j==m) return 1;
        if (i==n )return 0;
        if(dp[i][j]!=-1)  return dp[i][j];//stored answer already the we do not go below to recalculate

        if(s[i]==t[j])//matching char//take one mahcting // donot take this one matching but next one
        {
             return dp[i][j]= choices(s,t,n,m,i+1,j+1)+choices(s,t,n,m,i+1,j);

        }

        else //not matching char move forward
         return  dp[i][j]= choices(s,t,n,m,i+1,j);
    }
};