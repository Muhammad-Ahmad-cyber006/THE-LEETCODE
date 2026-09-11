class Solution {
public:
    int totalNumbers(vector<int>& n) 
    {
        set<int> s;
        for(int i=0;i<n.size();i++)
        {
            for(int j=0;j<n.size();j++)
            {
                for(int k=0;k<n.size();k++)
                {
                    if(i==j||i==k||j==k||n[i]==0||n[k]%2!=0)
                        continue;
                    int num=n[i]*100+n[j]*10+n[k];
                    s.insert(num);
                }
            }
        }
        return s.size();
    }
};