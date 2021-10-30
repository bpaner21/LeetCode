class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size(), pivot = 0;
        
        // dutch flag sort
        while (pivot < high) {
            if (nums[pivot] < 1) { // if nums[pivot] == 0
                
                swap (nums[pivot++], nums[low++]);
            }
            else if (nums[pivot] > 1) { // if nums[pivot] == 2
                
                swap(nums[pivot], nums[--high]);
            }
            else {// if equal to pivot 
                
                ++pivot;
            }
        }
    }
};