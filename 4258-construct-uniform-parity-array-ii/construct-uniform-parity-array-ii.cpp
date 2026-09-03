class Solution {
public:
    bool uniformArray(vector<int>& nums1) 
    {
        int minOdd = INT_MAX, minEven = INT_MAX;

        for(int x : nums1)
        {
            if(x & 1)
                minOdd = min(minOdd, x);
            else
                minEven = min(minEven, x);
        }

        // Sirf even numbers hain  already uniform
        if(minOdd == INT_MAX)
            return true;

        // Sabse chota even, smallest odd se chota hua
        // toh dono parity ko uniform nahi bana sakte
        return minEven > minOdd;
    }
};