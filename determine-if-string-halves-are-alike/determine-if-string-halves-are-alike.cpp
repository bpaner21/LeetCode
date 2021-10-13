class Solution {
public:
    bool halvesAreAlike(string& s) {
        
        int l1 = s.length(), l2 = l1 >> 1;
        short int count = 0;
        
        for (int i = 0; i < l2; ++i) {
            
            if (isVowel(s[i])) {
                
                ++count;
            }
        }
        
        for (int j = l2; j < l1; ++j) {
            
            if (isVowel(s[j])) {
                
                --count;
            }
        }
        
        return count == 0;
    }
    
private:
    bool isVowel(char& ch) {
        
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
};