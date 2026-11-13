class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums,int k)
    {
        int n=nums.size(),LOG=1;
        while((1<<LOG)<=n) LOG++;

        vector<long long> pref(n+1,0);

        // Prefix sum helps calculate the sum of any range in O(1).
        for(int i=0;i<n;i++)
            pref[i+1]=pref[i]+nums[i];

        // Find the next index containing a strictly greater element.
        // A monotonic stack helps find these indices in O(n).
        vector<int> nxt(n,n),st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.back()]<=nums[i])
                st.pop_back();

            if(!st.empty())
                nxt[i]=st.back();

            st.push_back(i);
        }

        // Binary lifting tables:
        // up[j][i] = index reached after jumping 2^j next-greater links.
        // cost[j][i] = increments needed to complete those blocks.
        vector<vector<int>> up(LOG,vector<int>(n+1,n));
        vector<vector<long long>> cost(LOG,vector<long long>(n+1,0));

        for(int i=0;i<n;i++)
        {
            up[0][i]=nxt[i];

            // Between i and its next greater element,
            // every element must be increased to nums[i].
            cost[0][i]=1LL*nums[i]*(nxt[i]-i)-(pref[nxt[i]]-pref[i]);
        }

        // Build binary lifting tables.
        for(int j=1;j<LOG;j++)
        {
            for(int i=0;i<n;i++)
            {
                int mid=up[j-1][i];

                up[j][i]=up[j-1][mid];
                cost[j][i]=cost[j-1][i]+cost[j-1][mid];
            }
        }

        // Calculate minimum increments needed for subarray [l,r].
        auto getCost=[&](int l,int r)
        {
            long long total=0;
            int p=l;

            // Jump over complete blocks using binary lifting.
            for(int j=LOG-1;j>=0;j--)
            {
                if(up[j][p]<=r+1)
                {
                    total+=cost[j][p];
                    p=up[j][p];
                }
            }

            // Handle the remaining incomplete block.
            if(p<=r)
                total+=1LL*nums[p]*(r-p+1)-(pref[r+1]-pref[p]);

            return total;
        };

        long long ans=0;

        // Fix the right endpoint and binary search the smallest
        // left endpoint whose required increments do not exceed k.
        for(int r=0;r<n;r++)
        {
            int lo=0,hi=r;

            while(lo<hi)
            {
                int mid=lo+(hi-lo)/2;

                if(getCost(mid,r)<=k)
                    hi=mid;
                else
                    lo=mid+1;
            }

            // Every subarray starting from lo to r is valid.
            ans+=r-lo+1;
        }

        return ans;
    }
};