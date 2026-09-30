class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int maxSum=0;
        int minSum=0;
        int curMax=0;
        int curMin=0;
        for(int i=0;i<nums.size();i++)
        {
            // maximum positive subarray sum 
            curMax=max(nums[i],curMax+nums[i]);
            maxSum=max(maxSum,curMax);
            // minimum negative subarray sum 
            curMin=min(nums[i],curMin+nums[i]);
            minSum=min(minSum,curMin);
        }
        // positive aur negative sums ki maximum absolute value 
        return max(maxSum,abs(minSum));
    }
};