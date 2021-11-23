class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        unordered_map<int, int> map {};
        
        int count = 0;
        
        for (auto d : dominoes) {
            
            int aB = d[0] >= d[1] ? (d[0] * 10) + d[1] : (d[1] * 10) + d[0];
            
            if (map.find(aB) != map.end()) {
                
                count += map[aB];
                
                ++map[aB];
                
            } else {
                
                map[aB] = 1;
            }
        }
        
        return count;
    }
};