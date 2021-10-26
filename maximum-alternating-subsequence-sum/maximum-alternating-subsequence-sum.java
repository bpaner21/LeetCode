class Solution {
    public long maxAlternatingSum(int[] nums) {
        
        long even = 0, odd = 0;
        
        for (int n : nums) {
            
            even = Math.max(even, odd + n);
            
            odd = even - n;
        }
        
        return even;
    }
}