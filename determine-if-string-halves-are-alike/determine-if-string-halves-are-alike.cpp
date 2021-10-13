class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int length = s.length();
        short int count = 0;
        
        for (int i = 0; i < length / 2; ++i) {
            
            char c = s[i];
            
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                
                ++count;
            }
        }
        
        for (int j = length / 2; j < length; ++j) {
            
            char c = s[j];
            
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                
                --count;
            }
        }
        
        return count == 0;
    }
};