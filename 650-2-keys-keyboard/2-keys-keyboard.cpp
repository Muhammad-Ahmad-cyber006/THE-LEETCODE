class Solution {
public:
    // memo top down
    // int t[1001][1001];// memo

    // int slove (int currA,int clipA ,int n)
    // {
    //     if(currA==n)
    //     {
    //         return 0;
    //     }
    //     if(currA>n) return 1e9;
    //     if(t[currA][clipA]!=-1)
    //     {
    //         return t[currA][clipA];
    //     }

    //     int copyAllPaste=1+1+slove(currA+currA,currA,n);
    //     int paste=1+slove(currA+clipA,clipA,n);
    //     return t[currA][clipA]=min(paste,copyAllPaste);

    // }
    // int minSteps(int n) 
    // {
    //     if (n==0||n==1) return 0;

    //     memset(t,-1,sizeof(t));

    //     return 1+slove(1,1,n);


        
    // }


    //bottom up+greedy

    // int minSteps(int n)
    // {
    //     int t[1001];
    //     t[0]=0,t[1]=0,t[2]=2;
    //     for(int i=3;i<=n;i++){
    //         int factor=i/2;
    //         while(factor>=1)
    //         {
    //             if(i%factor==0){
    //             int y=t[factor];
    //             int copy=1;
    //             int paste=(i/factor)-1;
    //             t[i]=y+copy+paste;
    //             break;
    //             }
    //             else factor--;
    //         }
    //     }
    //     return t[n];
    // }
    //prime factorzation
    int minSteps(int n) {
        int ans=0;

        for(int i=2;i*i<=n;i++) 
        {
            while(n%i==0) 
            {
                ans+=i;
                n/=i;
            }
        }

        if(n>1) ans+=n;

        return ans;
    }
};