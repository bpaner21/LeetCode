class Solution {
public:
    int maximumWealth(const vector<vector<int>>& accounts) {
        
        int maxWealth = INT_MIN;
        
        for (const vector<int>& a : accounts) {
            
            maxWealth = max(maxWealth, accumulate(begin(a), end(a), 0));
        }
        
        return maxWealth;
    }
};