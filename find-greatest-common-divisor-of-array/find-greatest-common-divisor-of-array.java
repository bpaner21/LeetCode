class Solution {
    public int findGCD(int[] nums) {
        
        int nMin = 1001, nMax = 0, remainder;
        
        for (int n : nums) {
            
            nMin = Math.min(nMin, n);
            nMax = Math.max(nMax, n);
        }
        
        while (nMin > 0) {
            
            remainder = nMax % nMin;
            
            nMax = nMin;
            
            nMin = remainder;
        }
        
        return nMax;
    }
}