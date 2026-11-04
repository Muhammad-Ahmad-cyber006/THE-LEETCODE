class Solution {
public:
    bool isPalindrome(int x) 
    {

        std::string str = std::to_string(x);
    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());

    }
};