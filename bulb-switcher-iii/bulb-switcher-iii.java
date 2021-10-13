class Solution {
    public int numTimesAllBlue(int[] light) {
        
        int right = -1,     // the rightmost lit bulb
                count = 0;  // the number of moments all lit bulbs were blue
        
        for (int i = 0; i < light.length; ++i) {
            
            right = Math.max(right, light[i]);
            
            if (right == i + 1) { ++count; }
        }
        
        return count;
    }
}