class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
    int larger=*max_element(nums.begin(), nums.end());
        cout<<larger;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=larger-nums[i];

        }
        return count;
        
    }
};