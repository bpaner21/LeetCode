class Solution {
    public boolean check(int[] nums) {
        
        int decrease = 0, size = nums.length;
        
        for (int i = 0; i < size; ++i) {
            
            // nums[i] > nums[(i + 1) % size] allows for comparison between nums[size - 1] and nums[0]
            if (nums[i] > nums[(i + 1) % size]) { ++decrease;}
            
            // if there is more than one instance in the rotated array 
            // where a value decreases from the previous index,
            // the array is not properly sorted
            if (decrease > 1) { return false; }
        }
        
        return true;
    }
}