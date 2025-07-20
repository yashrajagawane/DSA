class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
        {
            return false;
        }
        long long int p=0,r=x;
        while(x > 0){
            int digit = x%10;
            p = p * 10 + digit;
            x = x/10;
        }

        return r == p;
    }
};