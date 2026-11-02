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
    int memo[101];
    int slove( vector<int>& nums,int i,int n )
    {
        if(i>=n) return 0;

        if(memo[i]!=-1) return memo[i];
        




    int steal=nums[i]+slove(nums,i+2,n);

    int skip=slove(nums,i+1,n);

        return memo[i]=max(steal,skip);

    }

     int rob(vector<int>& nums)
     {
        memset(memo,-1,sizeof(memo));
        return slove(nums,0,nums.size());

     } 
};