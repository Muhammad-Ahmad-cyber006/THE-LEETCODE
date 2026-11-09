class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> busy;
        vector<int> count(k,0);

        for(int i=0;i<k;i++)
            available.insert(i);

        for(int i=0;i<arrival.size();i++) {
            // Release servers whose tasks are completed.
            while(!busy.empty()&&busy.top().first<=arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // Drop request if all servers are busy.
            if(available.empty())
                continue;

            int target=i%k;
            auto it=available.lower_bound(target);

            // Wrap around if no server is found.
            if(it==available.end())
                it=available.begin();

            int server=*it;
            available.erase(it);
            count[server]++;

            // Assign request and store its finishing time.
            busy.push({(long long)arrival[i]+load[i],server});
        }

        int mx=*max_element(count.begin(),count.end());
        vector<int> ans;

        for(int i=0;i<k;i++) {
            if(count[i]==mx)
                ans.push_back(i);
        }

        return ans;
    }
};