class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) 
    {
        int n=s.size();
        vector<int> l(26,n),r(26,-1);

        // har character ki first aur last position nikal rahe hain
        for(int i=0;i<n;i++)
        {
            l[s[i]-'a']=min(l[s[i]-'a'],i);
            r[s[i]-'a']=i;
        }

        vector<pair<int,int>> v;

        // har character ka minimum valid interval bana rahe hain
        for(int c=0;c<26;c++)
        {
            if(r[c]==-1) continue;

            int a=l[c],b=r[c];
            bool ok=true;

            for(int i=a;i<=b;i++)
            {
                int x=s[i]-'a';

                // agar character ki first occurrence interval
                // se pehle hai to interval valid nahi hai
                if(l[x]<a)
                {
                    ok=false;
                    break;
                }

                // character ki last occurrence ko bhi include kar rahe hain
                b=max(b,r[x]);
            }

            if(ok)
                v.push_back({a,b});
        }

        // ending position ke according sort kar rahe hain
        sort(v.begin(),v.end(),[](auto &a,auto &b)
        {
            return a.second<b.second;
        });

        vector<string> ans;
        int last=-1;

        // non-overlapping intervals select kar rahe hain
        for(auto p:v)
        {
            if(p.first>last)
            {
                ans.push_back(s.substr(p.first,p.second-p.first+1));
                last=p.second;
            }
        }

        return ans;
    }
};