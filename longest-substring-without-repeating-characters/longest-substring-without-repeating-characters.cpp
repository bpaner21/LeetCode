class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        
        if (s.size() <= 1) { return s.size(); }
        
        int chars[256] { 0 }; 
        
        int left = 0, right = 0, maxSize = INT_MIN, currentSize = 0;
        
        while (right != s.size()) {
            
            ++chars[s[right]];
            
            ++currentSize;
            
            if (chars[s[right]] > 1) {
                
                while (chars[s[right]] > 1) {

                    --chars[s[left]];

                    ++left;
                    
                    --currentSize;
                }
            }
            
            maxSize = currentSize > maxSize ? currentSize : maxSize;
            
            ++right;
        }
        
        return maxSize;
    }
};