class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int left = 0, right = nums.size() - 1, p = nums.size();
        
        vector<int> sorted(p--, 0);
        
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
};