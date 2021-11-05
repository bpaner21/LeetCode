class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // If nums has length 1 or less, then it is already within the accepted parameters
        if (nums.size() < 1) { return nums.size(); }
        
        
        int k = 0;
        
        for (int n : nums) {
            
            /*
                [if (k < 1)] automatically sets num[0] equal to itself
                
                [if (nums[k - 1] != n)] checks if there is more than one instance of a unique element in the array
                
                [if (nums[k - 1] < n)] would also work but may be more difficult to intuit
            */
            
            if (k < 1 || nums[k - 1] != n) {
                
                nums[k++] = n;
            }
        }
        
        
        return k;
    }
};