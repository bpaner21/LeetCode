class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0, j = s.size() - 1;
        
        while (i < j) {
            
            while (i < j && isalnum(s[i]) == 0) { ++i; }
            while (i < j && isalnum(s[j]) == 0) { --j; }
            
            if (toupper(s[i]) != toupper(s[j])) { return false; }
            
            ++i;
            --j;
        }
        
        return true;
    }
};