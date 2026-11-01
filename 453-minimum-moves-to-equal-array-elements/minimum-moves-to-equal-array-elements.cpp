class Solution {
public:

    int minMoves(vector<int>& nums) 
    {
        int n= nums.size();
        int sum=0;
        int min_elei=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            min_elei=min(min_elei,nums[i]);
        }
        return sum-n*min_elei;

        
    }
};