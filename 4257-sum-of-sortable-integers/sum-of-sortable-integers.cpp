class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int k=1;k<=n;k++){
            if(n%k) continue;
            bool ok=true;
            int prev=0;
            for(int i=0;i<n;i+=k){
                int desc=-1,cnt=0;
                for(int j=i;j<i+k-1;j++){
                    if(nums[j]>nums[j+1]){
                        desc=j;
                        cnt++;
                    }
                }
                if(cnt>1){
                    ok=false;
                    break;
                }
                int start=(desc==-1)?i:desc+1;
                for(int j=0;j<k;j++){
                    int idx=i+(start-i+j)%k;
                    if(i>0&&j==0&&nums[idx]<prev){
                        ok=false;
                        break;
                    }
                    if(j>0){
                        int p=i+(start-i+j-1)%k;
                        if(nums[idx]<nums[p]){
                            ok=false;
                            break;
                        }
                    }
                }
                if(!ok) break;
                prev=nums[i+(start-i+k-1)%k];
            }
            if(ok) ans+=k;
        }
        return ans;
    }
};