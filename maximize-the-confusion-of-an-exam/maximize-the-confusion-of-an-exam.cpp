class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int maxFreq = 0, 
            left = 0, right = 0, 
            tr = 0, fa = 0;
        
        while (right < answerKey.length()) {
            
            // increment the number of times the current character appears in the current window
            int curFreq = answerKey[right] == 'T' ? ++tr : ++fa;
            
            
            // the maximum amount a character appears in the window
            maxFreq = max(maxFreq, curFreq);
            
            
            // (right - left + 1) is the size of the current window
            //
            // (maxFreq + k) is the theoretical maximum window size
            // (max count of character A in the window + the max amount character B can be flipped)
            //
            if (right - left + 1 > maxFreq + k) {
                
                // slide the window forward by decrementing the leftmost character's count
                // and incrementing the left window pointer
                if (answerKey[left] == 'T') { --tr; }
                
                else { --fa; } 
                
                
                ++left;
            }
            
            
            // increment the window size
            ++right;
        }
        
        // return the final size of the window
        return right - left;
    }
};