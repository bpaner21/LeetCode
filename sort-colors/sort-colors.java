class Solution {
    public void sortColors(int[] nums) {
        
        int low = 0, high = nums.length, pivot = 0;
        
        // dutch flag sort
        while (pivot < high) {
            if (nums[pivot] < 1) { // if nums[pivot] == 0
                                
                nums[pivot++] = nums[low];
                nums[low++] = 0;
            }
            else if (nums[pivot] > 1) { // if nums[pivot] == 2
                
                nums[pivot] = nums[--high];
                nums[high] = 2;
            }
            else {// if equal to pivot 
                
                ++pivot;
            }
        }
    }
}