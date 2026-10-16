class Solution {
public:
    static const int MOD=1e9+7;
    vector<long long> sum,sq,lazy;
    int n;
    void apply(int node,int l,int r,long long val){
        long long len=r-l+1;
        sq[node]=(sq[node]+2*val%MOD*sum[node]%MOD+len*val%MOD*val)%MOD;
        sum[node]=(sum[node]+len*val)%MOD;
        lazy[node]=(lazy[node]+val)%MOD;
    }
    void push(int node,int l,int r){
        if(lazy[node]==0||l==r)return;
        int mid=(l+r)/2;
        apply(node*2,l,mid,lazy[node]);
        apply(node*2+1,mid+1,r,lazy[node]);
        lazy[node]=0;
    }
    void update(int node,int l,int r,int ql,int qr){
        if(ql>r||qr<l)return;
        if(ql<=l&&r<=qr){
            apply(node,l,r,1);
            return;
        }
        push(node,l,r);
        int mid=(l+r)/2;
        update(node*2,l,mid,ql,qr);
        update(node*2+1,mid+1,r,ql,qr);
        sum[node]=(sum[node*2]+sum[node*2+1])%MOD;
        sq[node]=(sq[node*2]+sq[node*2+1])%MOD;
    }
    int sumCounts(vector<int>& nums) {
        n=nums.size();
        sum.assign(4*n,0);
        sq.assign(4*n,0);
        lazy.assign(4*n,0);
        unordered_map<int,int> last;
        long long ans=0;
        for(int i=0;i<n;i++){
            int l=last.count(nums[i])?last[nums[i]]+1:0;
            update(1,0,n-1,l,i);
            last[nums[i]]=i;
            ans=(ans+sq[1])%MOD;
        }
        return ans;
    }
};