class Solution {
public:
    bool uniformArray(vector<int>& nums1) 
    {
        int minOdd=INT_MAX;

        // Sabse chota odd number find karo
        for(int x:nums1)
        {
            if(x%2!=0)
                minOdd = min(minOdd,x);
        }

        // Agar koi odd nahi hai,already sab even hain
        if(minOdd==INT_MAX)
            return true;

        for(int x:nums1)
        {
            // Even number ko odd banane ke liye
            // usse chota odd number chahiye
            if(x%2==0 && x<minOdd)
                return false;
        }

        // Ab har even ko smallest odd se subtract karke
        // odd bana sakte hain, aur odd numbers ko same rakh sakte hain
        return true;
    }
};