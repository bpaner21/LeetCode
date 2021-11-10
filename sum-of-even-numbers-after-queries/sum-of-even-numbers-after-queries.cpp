class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> evenSums {};
        
        int currentSum = 0;
        
        for (int n : nums) { if (n % 2 == 0) { currentSum += n; } }
        
        for (int i = 0; i < queries.size(); ++i) {
            
            int j = queries[i][1];
            
            if (nums[j] % 2 == 0) { currentSum -= nums[j]; }
            
            nums[j] += queries[i][0];
            
            if (nums[j] % 2 == 0) { currentSum += nums[j]; }
            
            evenSums.push_back(currentSum);
        }
        
        return evenSums;
    }
};