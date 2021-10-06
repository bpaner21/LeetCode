class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        std::sort(nums.begin(), nums.end());
        
        long int left = 0, right = 0, result = 0, total = 0;
        
        while (right < nums.size()) {
            
            total += nums[right]; 
            
            while(nums[right] * (right - left + 1) > total + k) {
                
                total -= nums[left];
                    
                ++left;
            }
            
            result = std::max(result, (right - left + 1));
            
            ++right;
        }
        
        return result;
    }
};