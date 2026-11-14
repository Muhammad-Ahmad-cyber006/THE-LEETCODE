class Solution {
public:
    int minimumSumSubarray(vector<int>& nums,int l,int r)
    {
        int n=nums.size();
        vector<int> pref(n+1,0);

        // Build prefix sum array.
        // pref[i] stores the sum of elements from index 0 to i-1.
        for(int i=0;i<n;i++)
            pref[i+1]=pref[i]+nums[i];

        int ans=INT_MAX;

        // Try every possible starting index.
        for(int i=0;i<n;i++)
        {
            // Check all allowed subarray lengths from l to r.
            for(int len=l;len<=r;len++)
            {
                int j=i+len;

                // Make sure the subarray stays within array bounds.
                if(j>n) break;

                // Calculate subarray sum using prefix sums.
                int sum=pref[j]-pref[i];

                // We only need strictly positive sums.
                // Keep the minimum positive sum.
                if(sum>0)
                    ans=min(ans,sum);
            }
        }

        // If no valid positive subarray was found, return -1.
        return ans==INT_MAX?-1:ans;
    }
};