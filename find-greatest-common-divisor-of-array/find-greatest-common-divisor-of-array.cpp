class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int nMax = 0, nMin = 1001, remainder;
        
        for (int n : nums) {
            
            nMax = max(n, nMax);
            nMin = min(n, nMin);
        }
        
        while (nMin > 0) {
            
            remainder = nMax % nMin;
            
            nMax = nMin;
            
            nMin = remainder;
        }
        
        return nMax;
    }
};