class Solution {
public:
    int simpleGCD(int a,int b)
    {
        if(b==0)
        return a;
        else
        return simpleGCD(b,a%b);

    }
    int findGCD(vector<int>& nums) 
    {
        int a=INT_MIN;
        int b=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            a=max(a,nums[i]);
            b=min(b,nums[i]);

        }


        return simpleGCD(a,b);

        
    }
};