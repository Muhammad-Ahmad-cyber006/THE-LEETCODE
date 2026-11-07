class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;

        int i1=0,i2=1;

        while(i1<n&&i2<n)
        {
            int p=10;
            int temp=nums[i2];

            while(temp>=10)
            {
                p*=10;
                temp/=10;
            }

            int merged=nums[i1]*p+nums[i2];
            ans=min(merged,ans);

            i1+=2;
            i2+=2;
        }

        return ans;
    }
};