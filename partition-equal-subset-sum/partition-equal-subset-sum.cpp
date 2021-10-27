class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int target = 0;
        
        for (int n : nums) { target += n; }
         
        if (target % 2 == 1) { return false; }
        
        target /= 2;
        
        std::set<int> sums {0};
        
        for (int i = 0; i < nums.size(); ++i) {
            
            std::set<int> temp {};
            
            if (nums[i] == target) { return true; }
            
            for (int j : sums) {
                
                int newSum = j + nums[i];
                
                if (newSum == target) { return true; }
                
                if (newSum < target) { temp.insert(j + nums[i]); }
                
                temp.insert(j);
            }
            
            sums = temp;
        }
            
        return false;
    }
};