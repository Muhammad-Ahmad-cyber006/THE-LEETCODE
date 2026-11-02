class Solution {
public:
    //Brute Force
    // int slove(vector<int>& nums,int i)
    // {
    //     int n=nums.size();
    //     if(i>=n) return 0;


    //     int steal=nums[i]+slove(nums,i+2);

    //     int skip=slove(nums,i+1);

    //         return max(steal,skip);
    // }
    // int rob(vector<int>& nums) 
    // {
    //      return slove(nums,0);
        
    // }


    // top down memorization


    // int memo[101];
    // int slove( vector<int>& nums,int i,int n )
    // {
    //     if(i>=n) return 0;

    //     if(memo[i]!=-1) return memo[i];
        




    // int steal=nums[i]+slove(nums,i+2,n);

    // int skip=slove(nums,i+1,n);

    //     return memo[i]=max(steal,skip);

    // }

    //  int rob(vector<int>& nums)
    //  {
    //     memset(memo,-1,sizeof(memo));
    //     return slove(nums,0,nums.size());

    //  } 


    //bottom up
    int rob(vector<int>& nums)
    {
        
        
        int n=nums.size();
        if(n==1){return nums[0];}
        vector<int> t(n+1,0);
        //t[i] =max stolen money till i house
        t[0]=0;

        t[1]=nums[0];

        for(int i=2;i<=n;i++)
        {
            int steal=nums[i-1]+t[i-2];
            int skip=t[i-1];

            t[i]=max(steal,skip);
        }
        return t[n];
    }

};