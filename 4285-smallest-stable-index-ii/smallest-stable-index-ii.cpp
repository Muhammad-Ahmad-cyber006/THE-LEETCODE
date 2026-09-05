class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> minFromIndex(n);
        int mini=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            mini=min(mini,nums[i]);
            minFromIndex[i] =mini;
        }

        int maxi = INT_MIN;

        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);

             mini=minFromIndex[i];

            int score=maxi-mini;

            if(score<=k)
                return i;
        }

        return -1;
    }
};