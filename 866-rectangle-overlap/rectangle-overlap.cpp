class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) 
    {
        // x-axis par overlap check kar rahe hain
        // y-axis par overlap check kar rahe hain
        if(a[0]>=b[2]||b[0]>=a[2])
            return false;

        if(a[1]>=b[3]||b[1]>=a[3])
            return false;

        return true;
    }
};