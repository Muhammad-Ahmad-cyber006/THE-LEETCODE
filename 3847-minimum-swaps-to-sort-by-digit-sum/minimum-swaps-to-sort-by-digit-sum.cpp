class Solution {
public:
    int getDigitSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> afterSorted=nums;

        auto lambda=[&](int num1,int num2)
        {
            int ds1=getDigitSum(num1);
            int ds2=getDigitSum(num2);
            if (ds1!=ds2) return ds1<ds2;
            else return num1<num2;
        };
        sort(begin(afterSorted),end(afterSorted),lambda);
        unordered_map<int,int>valToIndx;
        for(int i=0;i<n;i++)
        {
            valToIndx[nums[i]]=i;
        }

        int sawp=0;

        for(int i=0; i<n;i++)
        {
            int expectedVal=afterSorted[i];
            int currVal=nums[i];
            if(expectedVal==currVal) continue;

            int idx=valToIndx[expectedVal];

            nums[i]=expectedVal;
            nums[idx]=currVal;

            valToIndx[expectedVal]=i;
            valToIndx[currVal]=idx;

            sawp++;
        }
        return sawp;


        
    }
};