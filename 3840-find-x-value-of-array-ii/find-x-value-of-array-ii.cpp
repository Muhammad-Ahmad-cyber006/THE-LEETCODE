class Solution {
public:
    struct Node
    {
        int prod;
        long long cnt[5];

        Node()
        {
            prod=1;

            // k maximum 5 hai isliye fixed array use kar rahe hain
            for(int i=0;i<5;i++)
                cnt[i]=0;
        }
    };

    int n,k;
    vector<int> a;
    vector<Node> st;

    Node merge(Node &A,Node &B)
    {
        Node C;

        // A aur B ko join karke poore segment ka product nikal rahe hain
        C.prod=(A.prod*B.prod)%k;

        // A ke saare prefixes naye segment me bhi prefixes reh rahe hain
        for(int i=0;i<k;i++)
            C.cnt[i]+=A.cnt[i];

        // B ke prefixes ko A ke complete segment ke baad laga rahe hain
        for(int i=0;i<k;i++)
        {
            // A ka product B ke prefix ke product se multiply kar rahe hain
            int x=(A.prod*i)%k;

            // naye product remainder ki frequency add kar rahe hain
            C.cnt[x]+=B.cnt[i];
        }

        return C;
    }

    void build(int p,int l,int r)
    {
        // leaf node me sirf ek element store kar rahe hain
        if(l==r)
        {
            // single element ka product % k store kar rahe hain
            st[p].prod=a[l]%k;

            // single element khud ek non-empty prefix ban raha hai
            st[p].cnt[a[l]%k]=1;

            return;
        }

        int m=(l+r)/2;

        // left aur right segments build kar rahe hain
        build(p*2,l,m);
        build(p*2+1,m+1,r);

        // dono child segments ko combine kar rahe hain
        st[p]=merge(st[p*2],st[p*2+1]);
    }

    void update(int p,int l,int r,int idx,int val)
    {
        // required index wale element tak pahunch rahe hain
        if(l==r)
        {
            // value ko permanently update kar rahe hain
            a[l]=val;

            // updated element ka product store kar rahe hain
            st[p].prod=val%k;

            // purani prefix frequencies remove kar rahe hain
            for(int i=0;i<5;i++)
                st[p].cnt[i]=0;

            // updated element ka single prefix store kar rahe hain
            st[p].cnt[val%k]=1;

            return;
        }

        int m=(l+r)/2;

        // index left segment me hai to left side update kar rahe hain
        if(idx<=m)
            update(p*2,l,m,idx,val);
        else
            update(p*2+1,m+1,r,idx,val);

        // child update hone ke baad parent ki information dobara bana rahe hain
        st[p]=merge(st[p*2],st[p*2+1]);
    }

    Node query(int p,int l,int r,int ql,int qr)
    {
        // poora current segment required range ke andar aa raha hai
        if(ql<=l&&r<=qr)
            return st[p];

        int m=(l+r)/2;

        // required range sirf left side me aa rahi hai
        if(qr<=m)
            return query(p*2,l,m,ql,qr);

        // required range sirf right side me aa rahi hai
        if(ql>m)
            return query(p*2+1,m+1,r,ql,qr);

        // required range dono children me divide ho rahi hai
        Node A=query(p*2,l,m,ql,qr);
        Node B=query(p*2+1,m+1,r,ql,qr);

        // left part ko right part ke saath order maintain karke merge kar rahe hain
        return merge(A,B);
    }

    vector<int> resultArray(vector<int>& nums,int K,
                            vector<vector<int>>& queries)
    {
        a=nums;
        n=a.size();
        k=K;

        // 4*n nodes allocate kar rahe hain
        st.resize(4*n);

        // complete array ka segment tree bana rahe hain
        build(1,0,n-1);

        vector<int> ans;

        // answer ke liye pehle se required space reserve kar rahe hain
        ans.reserve(queries.size());

        for(int qi=0;qi<queries.size();qi++)
        {
            int index=queries[qi][0];
            int value=queries[qi][1];
            int start=queries[qi][2];
            int x=queries[qi][3];

            // query ke according value ko permanently update kar rahe hain
            update(1,0,n-1,index,value);

            // prefix remove karne ke baad [start,n-1] range bach rahi hai
            Node cur=query(1,0,n-1,start,n-1);

            // suffix remove karne se is range ka koi bhi non-empty prefix bach raha hai
            // x remainder wale prefixes count kar rahe hain
            ans.push_back(cur.cnt[x]);
        }

        return ans;
    }
};