class Solution {
public:
    int minSumOfLengths(vector<int>& arr,int target) 
    {
        int n=arr.size(),ans=INT_MAX;
        vector<int> best(n+1,INT_MAX);

        int l=0,sum=0;

        for(int r=0;r<n;r++)
        {
            sum+=arr[r];

            while(sum>target)
                sum-=arr[l++];

            if(sum==target)
            {
                int len=r-l+1;

                // current subarray se pehle wala shortest subarray
                if(best[l]!=INT_MAX)
                    ans=min(ans,len+best[l]);

                // current subarray ko best me store kar rahe hain
                best[r+1]=min(best[r],len);
            }
            else
                best[r+1]=best[r];
        }

        return ans==INT_MAX?-1:ans;
    }
};