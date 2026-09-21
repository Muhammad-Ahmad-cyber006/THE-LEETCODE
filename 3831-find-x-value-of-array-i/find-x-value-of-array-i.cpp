class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
         vector<long long> dp(k,0),ans(k,0);

        for(int i=0;i<nums.size();i++)
        {
            vector<long long> cur(k,0);

            // sirf nums[i] se naya subarray bana rahe hain
            cur[nums[i]%k]++;

            // purane subarrays ke end par nums[i] add kar rahe hain
            for(int r=0;r<k;r++)
            {
                int x=(r*(nums[i]%k))%k;
                cur[x]+=dp[r];
            }

            // current ending wale sab subarrays count kar rahe hain
            for(int r=0;r<k;r++)
            {
                ans[r]+=cur[r];
                dp[r]=cur[r];
            }
        }

        return ans;
    }
};