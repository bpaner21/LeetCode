class Solution {
public:
    bool backspaceCompare(const string& s, const string& t) {
        
        // this can be solved with a stack,
        // but that would not be O(1) space
        
        int i = s.length() - 1, j = t.length() - 1;
        
        int skipS = 0, skipT = 0;
        
        // loop backwards starting from the ends
        // of strings s and t
        while (i >= 0 || j >= 0)
        {
            // if the loop runs into a '#' symbol in s
            // decrement its current index
            // and increase its skip count
            if (i >= 0 && s[i] == '#') {
                
                ++skipS;
                
                --i;
                
                continue;
            }
            
            // if the skip count for s is greater than 0,
            // decrement its index and skip count
            // 
            // these two if-statements together 
            // simulate a backspace function in O(n) time and O(1) space
            if (i >= 0 && skipS > 0) {
                
                --skipS;
                
                --i;
                
                continue;
            }

            
            // backspace functions for t
            if (j >= 0 && t[j] == '#') {   
                
                ++skipT;
                
                --j;
                
                continue;
            }
            
            if (j >= 0 && skipT > 0) {
                
                --skipT;
                
                --j;
                
                continue;
            }
            
            
            // once the backspace functions have concluded
            // i and j should point to the same character
            // otherwise s and t are not equal strings
            if (i >= 0 && j >= 0 && s[i] == t[j]) {
                
                --i;
                
                --j;
            }
            else {
                
                return false;
            }
        }
        
        // if the loop concluded and i != j,
        // then s and t are different strings of unqual length
        // (if s and t are equal, i = j = -1)
        return (i == j); 
    }
};