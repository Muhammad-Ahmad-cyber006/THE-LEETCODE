class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //brute froce
        int i=0;
        vector<int> result;
        while(i<nums.size())
        {   
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }

            }
            i++;

        }
 
        return result;

        
    }
};