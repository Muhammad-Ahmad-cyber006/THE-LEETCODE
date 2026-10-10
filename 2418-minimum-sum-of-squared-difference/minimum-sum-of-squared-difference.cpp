class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        long long k=(long long)k1+k2;
        vector<int> diff(nums1.size());
        int mx=0;

        for(int i=0;i<nums1.size();i++) 
        {
            diff[i]=abs(nums1[i]-nums2[i]);
            mx=max(mx,diff[i]);
        }

        long long total=0;
        for(int x:diff)
            total+=x;

        if(total<=k)
            return 0;

        int l=0,r=mx;

        while(l<r) 
        {
            int mid=l+(r-l)/2;
            long long need=0;

            for(int x:diff)
                if(x>mid)
                    need+=x-mid;

            if(need<=k)
                r=mid;
            else
                l=mid+1;
        }

        int limit=l;
        long long remaining=k;
        long long ans=0;

        for(int &x:diff) 
        {
            if(x>limit) 
            {
                remaining-=x-limit;
                x=limit;
            }
        }

        for(int &x:diff) 
        {
            if(remaining>0 && x==limit && limit>0) 
            {
                x--;
                remaining--;
            }
            ans+=1LL*x*x;
        }

        return ans;
    }
};