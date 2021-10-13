class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        
        int right = INT_MIN,    // the rightmost lit bulb
                count = 0;      // the number of moments all lit bulbs were blue
        
        for (int i = 0; i < light.size(); ++i) {
            
            right = max(right, light[i]);
            
            if (right == i + 1) { ++count; }
        }
        
        return count;
    }
};