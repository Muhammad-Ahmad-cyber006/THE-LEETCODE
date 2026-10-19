// t[i][j]:- longest subseq bwt s1 of len i 
//s2 of length j in bottom up we return t[m][n]


class Solution {
public:
    // int m,n;

    // int t[1001][1001];//memo
    // int slove(string s1,string s2,int i,int j)
    // {
    //     if(i>=m|| j>=n)
    //     {
    //         return 0;
    //     }
    //     if(t[i][j]!=-1)
    //     {
    //         return t[i][j];
    //     }
    //     if(s1[i]==s2[j])
    //     {
    //         return t[i][j]=1+slove(s1,s2,i+1,j+1);
    //     }
    //     else
    //     {
    //         return t[i][j]=max(slove(s1,s2,i+1,j),slove(s1,s2,i,j+1));
    //     }
    // }
    // int longestCommonSubsequence(string text1, string text2) 
    // {
    //     m=text1.size(),n=text2.size();
    //     memset(t,-1,sizeof(t));
    //     return slove(text1,text2,0,0);
        
    // }
    int longestCommonSubsequence(string s1, string s2) // bottom up
    {
        int m=s1.size();
        int n= s2.size();
        vector<vector<int>> t(m+1,vector<int>(n+1));

        //first row and col will be zero
        for(int row=0;row<m+1;row++)
        {
            t[row][0]=0;
        }
        for(int col=0;col<n+1;col++)
        {
            t[0][col]=0;
        }


        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
            if(s1[i-1]==s2[j-1])
            {
                t[i][j]=1+t[i-1][j-1];

            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
            }
        }
        return t[m][n];
    }
};