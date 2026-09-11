class Solution {
public:
    int totalNumbers(vector<int>& n) 
    {
        int m[10]={0};
        int count=0;

        // har digit ki frequency store karo
        for(int x:n)
            m[x]++;

        // first digit 1-9 hona chahiye 0 nahi
        for(int i=1;i<10;i++)
        {
            if(!m[i]) continue;
            else m[i]--; // i digit use kar lo

            // second digit 0-9 kuch bhi ho sakta hai
            for(int j=0;j<10;j++)
            {
                if(!m[j]) continue;
                else m[j]--; // j digit use kar lo

                // last digit even hona chahiye: 0,2,4,6,8
                for(int k=0;k<10;k+=2)
                {
                    if(m[k])
                        count++;
                }

                m[j]++; // j digit wapas
            }

            m[i]++; // i digit wapas
        }

        return count;
    }
};
// class Solution {
// public:
//     int totalNumbers(vector<int>& n) 
//     {
//         set<int> s;
//         for(int i=0;i<n.size();i++)
//         {
//             for(int j=0;j<n.size();j++)
//             {
//                 for(int k=0;k<n.size();k++)
//                 {
//                     if(i==j||i==k||j==k||n[i]==0||n[k]%2!=0)
//                         continue;
//                     int num=n[i]*100+n[j]*10+n[k];
//                     s.insert(num);
//                 }
//             }
//         }
//         return s.size();
//     }
// };