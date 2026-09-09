class Solution {
public:
    long long countCommas(long long n) 
{
    long long c1 = 0;
    long long c2 = 0;
    long long c3 = 0; 
    long long c4 = 0;
    long long c5 = 0;

        if (n<1000) 
        {
            return 0;
        }

        if (n>=1000) 
        {
            c1=n-999;
        }

        if (n>=1000000) 
        {
            c2=n-999999;
        }

        if (n>=1000000000LL) 
        {
            c3=n-999999999;
        }

        if (n>=1000000000000LL) 
        {
            c4=n-999999999999LL;
        }

        if (n>=1000000000000000LL) 
        {
            c5=n-999999999999999LL;
        }

        return c1+c2+c3+c4+c5;
    }
};