class Solution {
public:
    bool valid(string s) {
        int count=0;

        for(char ch:s) {
            if(ch=='(')
                count++;
            else if(ch==')') {
                count--;
                if(count<0)
                    return false;
            }
        }

        return count==0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found=false;

        while(!q.empty() && !found) {
            int n=q.size();

            while(n--) {
                string cur=q.front();
                q.pop();

                if(valid(cur)) {
                    ans.push_back(cur);
                    found=true;
                }

                if(found)
                    continue;

                for(int i=0;i<cur.size();i++) {
                    if(cur[i]!='(' && cur[i]!=')')
                        continue;

                    string next=cur.substr(0,i)+cur.substr(i+1);

                    if(!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};