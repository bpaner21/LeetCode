class Solution {
    public int maxFrequency(int[] nums, int k) {
        
        Arrays.sort(nums);
        
        int result = 0, left = 0;
        long total = 0;
        
        for (int right = 0; right < nums.length; ++right) {
            
            total += nums[right];
            
            while (nums[right] * (right - left + 1) > total + k) {
                
                total -= nums[left];
                
                ++left;
            }
            
            result = Math.max(result, right - left + 1);
        }
        
        return result;
    }
}