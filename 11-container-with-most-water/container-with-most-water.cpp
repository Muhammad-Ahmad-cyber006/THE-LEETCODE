class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int l=0;
        int r=height.size()-1;
        int Max=0;

        while(l<r)
        {
            int wall=min(height[l],height[r]);
            int width=r-l;

            int area=wall*width;

            Max=max(Max,area);
            
            if(height[l]<height[r])
                l++;
            else
                r--;
        }

        return Max;
    }
};