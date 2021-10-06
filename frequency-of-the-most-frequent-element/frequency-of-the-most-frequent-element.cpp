class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        std::sort(nums.begin(), nums.end());
        
        int result = 0, left = 0;
        long int total = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            
            total += nums[right]; 
            
            while(nums[right] * (long)(right - left + 1) > total + k) {
                
                total -= nums[left];
                    
                ++left;
            }
            
            result = std::max(result, (right - left + 1));
        }
        
        return result;
    }
};
