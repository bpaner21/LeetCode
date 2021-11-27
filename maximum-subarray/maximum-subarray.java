class Solution {
    public int maxSubArray(int[] nums) {
        
        int localMax = 0, globalMax = Integer.MIN_VALUE;
        
        for (int i = 0; i < nums.length; ++i) {
            
            localMax = Math.max(nums[i], nums[i] + localMax);
            
            globalMax = globalMax > localMax ? globalMax : localMax;
        }
        
        return globalMax;
    }
}