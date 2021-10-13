class Solution {
public:
    bool halvesAreAlike(string s) {
        
        short int count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || 
                s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                
                count += 2*i < s.length() ? 1 : -1;
            }
        }
        
        return count == 0;
    }
};