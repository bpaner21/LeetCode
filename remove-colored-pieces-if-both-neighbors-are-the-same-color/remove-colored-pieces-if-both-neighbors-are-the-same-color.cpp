class Solution {
public:
    bool winnerOfGame(string colors) {
        
        if (colors.size() < 3) { return false; }
        
        int aCount = 0, bCount = 0, i = 0;
        
        while (i < colors.size()) {
            
            char ch = colors[i];
            int curCount = 0;
            
            while (i < colors.size() && colors[i] == ch) {
                
                ++i;
                ++curCount;
            }
            
            curCount = std::max(0, curCount - 2);
            
            if (ch == 'A') { aCount += curCount; }
            
            else { bCount += curCount; } 
        }
        
        
        return aCount > bCount;
    }
};