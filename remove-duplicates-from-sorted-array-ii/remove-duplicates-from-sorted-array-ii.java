class Solution {
    public int removeDuplicates(int[] nums) {
        
        // If nums has length 2 or less, array is already within accepted boundaries
        if (nums.length < 3) { return nums.length; }
        
        
        int k = 0;
        
        for (int n : nums) {
            
            /*
                [if (k < 2)] automatically sets num[0] and nums[1] equal to themselves
                
                [if (nums[k - 2] != n)] checks if there are more than two instances of a unique element in the array
                
                [if (nums[k - 2] < n)] would also work but may be more difficult to intuit
            */
            
            if (k < 2 || nums[k - 2] != n) {
                
                nums[k++] = n;
            }
        }
        
        
        return k;
    }
}