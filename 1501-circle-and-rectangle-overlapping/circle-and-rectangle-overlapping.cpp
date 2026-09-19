class Solution {
public:
    bool checkOverlap(int r,int xc,int yc,int x1,int y1,int x2,int y2) 
    {
        // circle center ke closest x point ko find kar rahe hain
        int x=max(x1,min(xc,x2));

        // circle center ke closest y point ko find kar rahe hain
        int y=max(y1,min(yc,y2));

        // closest point aur center ka distance check kar rahe hain
        int dx=x-xc;
        int dy=y-yc;

        return dx*dx+dy*dy<=r*r;
    }
};