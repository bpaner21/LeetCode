class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        long long even = 0, odd = 0;
        
        for (int n : nums) {
            
            even = std::max(even, odd + n);
            
            odd = even - n;
        }
        
        return even;
    }
};