class Solution {
public:
 int gcdi(int a,int b) 
 {
    while (b!=0) 
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
 }  
    string gcdOfStrings(string str1, string str2) 
    {
        int n1=str1.length();
        int n2=str2.length();
        if (str1+str2!=str2+str1)
        {
            return "";
        }
        return str1.substr(0,gcdi(n1,n2));
    }    
        
    
};