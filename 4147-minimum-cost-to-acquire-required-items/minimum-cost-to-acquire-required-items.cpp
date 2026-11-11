class Solution {
public:
    long long minimumCost(int cost1,int cost2,int costBoth,int need1,int need2)
    {
        // Find the common units required by both types
        long long both=min(need1,need2);

        // Choose between one type 3 item or one type 1 + type 2
        long long ans=both*min(costBoth,cost1+cost2);

        // Cover extra type 1 requirements using the cheaper item
        if(need1>need2)
            ans+=1LL*(need1-need2)*min(cost1,costBoth);

        // Cover extra type 2 requirements using the cheaper item
        else
            ans+=1LL*(need2-need1)*min(cost2,costBoth);

        return ans;
    }
};