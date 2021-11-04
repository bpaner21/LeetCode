class Solution {
public:
    int longestWPI(const vector<int>& hours) {
        
        if (hours.size() == 1) { return (hours[0] > 8 ? 1 : 0); }
        
        int score = 0, maxInterval = 0;
        
        unordered_map<int, int> map {};
        
        for (int i = 0; i < hours.size(); ++i) {
            
            score += (hours[i] > 8 ? 1 : -1);
            
            // only record the first instance that a specific score is found
            if (map.find(score) == map.end()) { map[score] = i; }
            
            if (score > 0) { // if there have been more tiring days than not (strictly incrementing interval)
                
                maxInterval = i + 1; 
            }
            else if (map.find(score - 1) != map.end()) { // if there exists an incrementing interval
                
                maxInterval = max(maxInterval, i - map[score - 1]);
            }
        }
        
        return maxInterval;
    }
};