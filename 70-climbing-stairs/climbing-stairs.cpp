class Solution {
public:
    int climbStairs(int n) {
        int one=1;int two =1;
        int i=0;
        while(i<n-1){
            i++;
            int temp=one;
            one=one+two;
            two=temp;
        }
        return one;

        
    }
};