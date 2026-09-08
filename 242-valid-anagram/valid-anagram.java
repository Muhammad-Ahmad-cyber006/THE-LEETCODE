class Solution {
    public boolean isAnagram(String s, String t) 
    {
        //BF
        //take one ele and compare it with every ele in other string
        //len check
        if(s.length()!=t.length()) return false;
         int []charCount=new int[26];// this is constant space and is not growing 
        // to check freq

        for (int i=0;i<s.length();i++)
        {
            charCount[s.charAt(i)-'a']++;
            charCount[t.charAt(i)-'a']--;

        }
        // check if every thing is count is zero
        for(int count: charCount)// it count store every value in charcount count one by one if one count is not zero then false
        
        {
            if(count!=0) return false;
        }
         return true;

    }
}