class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        int n=img1.size(),ans=0;

        // har possible row aur column shift try kar rahe hain
        for(int r=-(n-1);r<n;r++)
        {
            for(int c=-(n-1);c<n;c++)
            {
                int count=0;

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        int x=i+r,y=j+c;

                        // translated position matrix ke andar hai
                        if(x>=0&&x<n&&y>=0&&y<n)
                        {
                            // dono images me 1 aa raha hai
                            if(img1[i][j]&&img2[x][y])
                                count++;
                        }
                    }
                }

                ans=max(ans,count);
            }
        }

        return ans;
    }
};