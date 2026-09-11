class Solution {
public:
    int closestTarget(vector<string>& words, string t, int s) 
    {
        int n=words.size();

        // Agar starting position par hi target hai
        if(words[s]==t)
            return 0;

        int count=0;
        int c1=-1;
        int c2=-1;
        // RIGHT direction
        for(int i=s+1;count<n;i++)
        {
            // Circular array:
            // last index ke baad wapas 0 par jao
            if(i == n)
                i = 0;

            count++;

            if(words[i]==t)
            {
                c1=count;
                break;
            }
        }

        count = 0;

        // LEFT direction
        for(int i=s-1;count<n;i--)
        {
            // Circular array:
            // index 0 se pehle last index par jao
            if(i<0)
                i=n-1;  // NOT n

            count++;

            if(words[i]==t)
            {
                c2=count;
                break;
            }
        }
        if(c1 == -1)
            return c2;

        if(c2 == -1)
            return c1;


        // Dono directions ki minimum distance
        return min(c1,c2);
    }
};