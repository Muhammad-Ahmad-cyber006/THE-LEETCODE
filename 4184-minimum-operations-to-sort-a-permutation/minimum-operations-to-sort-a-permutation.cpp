class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        auto check=[&](vector<int>& a) {
            int p=find(a.begin(),a.end(),0)-a.begin();
            for(int i=0;i<n;i++)
                if(a[(p+i)%n]!=i) return -1;
            return p;
        };

        int p=check(nums);
        int ans=INT_MAX;
        if(p!=-1) ans=min(p,n-p+2);

        reverse(nums.begin(),nums.end());
        p=check(nums);
        if(p!=-1) ans=min(ans,1+min(p,n-p));

        return ans==INT_MAX?-1:ans;
    }
};