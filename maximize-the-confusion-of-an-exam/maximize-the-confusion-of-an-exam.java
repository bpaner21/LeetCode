class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        
        int maxFreq = 0, 
            left = 0, right = 0, 
            tr = 0, fa = 0;
        
        while (right < answerKey.length()) {
            
            // the number of times the current character appears in the window
            int curFreq = answerKey.charAt(right) == 'T' ? ++tr : ++fa;
            
            
            // the maximum amount a character appears in a window
            maxFreq = Math.max(maxFreq, curFreq);
            
            
            // (right - left + 1) is the size of the current window
            //
            // (maxFreq + k) is the theoretical maximum window size
            // (max count of character A in a window + the max amount character B can be flipped)
            if (right - left + 1 > maxFreq + k) {
                
                // slide the window forward by decrementing the leftmost value count
                // and moving up the left pointer
                if (answerKey.charAt(left) == 'T') { --tr; }
                
                else { --fa; } 
                
                ++left;
            }
            
            ++right;
        }
        
        // return the final size of the window
        return right - left;
    }
}