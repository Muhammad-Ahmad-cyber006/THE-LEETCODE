class Solution {
public:
//bottom up dp
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        int t[n+1][m+1];

        for(int i=0;i<=n;i++)
            t[i][0]=i;

        for(int j=0;j<=m;j++)
            t[0][j]=j;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    t[i][j]=t[i-1][j-1];
                }
                else
                {
                    t[i][j]=1+min({t[i-1][j-1],t[i][j-1],t[i-1][j]});
                }
            }
        }

        return t[n][m];
    }
};