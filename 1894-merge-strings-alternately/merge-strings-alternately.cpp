class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string result=word1+word2;
        int j=0;
        int i=0;
        
        while(i<word1.size() && i<word2.size())
        {
            result[j++]=word1[i];
            result[j++]=word2[i];
            i++;
        }
        
        while(i<word1.size())
        {
            result[j++]=word1[i++];
        }
        while(i<word2.size())
        {
            result[j++]=word2[i++];
        }

        return result;

        
    }
};