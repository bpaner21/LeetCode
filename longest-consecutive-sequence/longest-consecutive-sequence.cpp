class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::unordered_set<int> s(nums.begin(), nums.end());
        
        int lcs = 0;
        
        for (int i : s) {
            
            if (s.find(i - 1) == s.end()) { 
                
                int current = i + 1;
                
                // std::unordered_set::erase returns 1 if a key value was found and erased
                while (s.erase(current) == 1) { ++current; }
                
                lcs = std::max(lcs, current - i);
            }
        }
        
        return lcs;
    }
};