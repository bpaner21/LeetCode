class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int lastIndex[26] {0};
        
        vector<int> partitions {};
        
        // record the rightmost index of each letter in s
        for (int i = 0; i < s.size(); ++i) {
            
            lastIndex[s[i] - 'a'] = i;
        }
        
        // using the record of the rightmost indices as end points,
        // create partitions that contain every appearnce of the letters they hold
        for (int left = 0; left < s.size(); ++left) {
            
            int right = left;
            
            int partitionEnd = lastIndex[s[left] - 'a'];
            
            while (left < partitionEnd) {
                
                ++left;
                
                partitionEnd = max(partitionEnd, lastIndex[s[left] - 'a']);
            }
            
            partitions.push_back(left - right + 1);
        }
        
        return partitions;
    }
};