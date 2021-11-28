class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int nMin = *std::min_element(nums.begin(), nums.end()), 
            nMax = *std::max_element(nums.begin(), nums.end());
        
        return std::gcd(nMin, nMax);
    }
};