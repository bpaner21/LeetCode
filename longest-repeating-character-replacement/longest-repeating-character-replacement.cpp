class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxFreq = 0, left = 0, right = 0;
        
        int ch[26] { };
        
        
        while (right < s.size()) {
            
            // increment the number of times the current character appears in the current window
            int curFreq = ++ch[s[right] - 'A'];
            
            
            // the maximum amount a character appears in the window
            maxFreq = max(maxFreq, curFreq);
            
            
            // (right - left + 1) is the size of the current window
            //
            // (maxFreq + k) is the theoretical maximum window size
            // (max count of a character in the window + the max amount other characters can be flipped)
            //
            if (right - left + 1 > maxFreq + k) {
                
                // slide the window forward by decrementing the leftmost character's count
                // and incrementing the left window pointer
                --ch[s[left] - 'A'];              
                
                ++left;
            }
            
            
            // increment the window size
            ++right;
        }
        
        // return the final size of the window
        return right - left;
    }
};