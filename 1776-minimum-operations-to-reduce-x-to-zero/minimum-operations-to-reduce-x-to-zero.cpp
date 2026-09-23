class Solution {
public:
    int minOperations(vector<int>& nums,int x) 
    {
        int n=nums.size();
        int sum=0;

        // poore array ka total sum nikal rahe hain
        for(int i=0;i<n;i++)
            sum+=nums[i];

        // agar middle subarray ka sum target hoga
        int target=sum-x;

        // target negative hai to possible answer nahi ban raha
        if(target<0)
            return -1;

        int l=0;
        int curr=0;
        int best=-1;

        // longest subarray with sum = target find kar rahe hain
        for(int r=0;r<n;r++)
        {
            // right side se current element add kar rahe hain
            curr+=nums[r];

            // sum target se bara ho raha hai to left se remove kar rahe hain
            while(l<=r&&curr>target)
            {
                curr-=nums[l];
                l++;
            }

            // required sum mil raha hai
            if(curr==target)
            {
                // maximum length ka valid subarray store kar rahe hain
                best=max(best,r-l+1);
            }
        }

        // valid middle subarray nahi mila
        if(best==-1)
            return -1;

        // middle ko chhor kar baaki elements remove kar rahe hain
        return n-best;
    }
};