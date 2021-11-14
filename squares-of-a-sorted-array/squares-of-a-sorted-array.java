class Solution {
    public int[] sortedSquares(int[] nums) {
        
        int left = 0, right = nums.length - 1, p = nums.length;
        
        int sorted[] = new int[p--];
        
        while (left <= right) {
            
            int a = nums[left] * nums[left], b = nums[right] * nums[right];
                
            if (a >= b) {
                
                sorted[p--] = a;
                
                ++left;
            }
            else {
                
                sorted[p--] = b;
                
                --right;
            }
            
        }
        
        return sorted;
    }
}