class Solution {
public:
    using vl=vector<long long>;
    using vi=vector<int>;

    vector<int> maximumWeight(vector<vector<int>>& intervals) 
    {
        int n=intervals.size();

        // {right,left,index} store kar rahe hain
        vector<array<long long,3>> a(n);

        for(int i=0;i<n;i++)
            a[i]={intervals[i][1],intervals[i][0],i};

        // right endpoint ke according sort kar rahe hain
        sort(a.begin(),a.end());

        vl r(n);

        for(int i=0;i<n;i++)
            r[i]=a[i][0];

        // dp[i][k] me first i intervals ka best answer store kar rahe hain
        // pair me weight aur selected indices rakh rahe hain
        vector<vector<pair<long long,vi>>> dp(n+1,vector<pair<long long,vi>>(5));

        for(int i=1;i<=n;i++)
        {
            // compatible previous interval ko binary search kar rahe hain
            // right < current left check kar rahe hain
            int p=lower_bound(r.begin(),r.end(),a[i-1][1])-r.begin();

            for(int k=1;k<=4;k++)
            {
                // current interval ko skip kar rahe hain
                auto x=dp[i-1][k];

                // current interval ko select kar rahe hain
                auto y=dp[p][k-1];

                // current interval ki weight add kar rahe hain
                y.first+=intervals[a[i-1][2]][2];

                // current interval ka index add kar rahe hain
                y.second.push_back(a[i-1][2]);

                // indices ko sort kar rahe hain
                sort(y.second.begin(),y.second.end());

                // maximum weight choose kar rahe hain
                // weight same hone par lexicographically smaller array choose kar rahe hain
                if(y.first>x.first||(y.first==x.first&&y.second<x.second))
                    dp[i][k]=y;
                else
                    dp[i][k]=x;
            }
        }

        return dp[n][4].second;
    }
};