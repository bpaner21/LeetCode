class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int& target) {
        
        vector<int> sum;
        
        // value, index
        unordered_map<int, int> uMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            int difference = target - nums[i];
            
            if (uMap.find(difference) != uMap.end()) {
                
                sum.push_back(uMap[difference]);
                sum.push_back(i);                
                
                return sum;
            }
            
            uMap[nums[i]] = i;
        }
        
        return sum;
    }
};