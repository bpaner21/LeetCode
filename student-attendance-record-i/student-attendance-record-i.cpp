class Solution {
public:
    bool checkRecord(string s) {
        
        int a = 0, l = 0;
        
        for (auto itr = s.begin(); itr != s.end(); ++itr) {
            
            if (*itr == 'A') { ++a; }
            
            if (*itr == 'L') { ++l; }
            else { l = 0; }
            
            if (l >= 3) { return false; }
        }
        
        return (a < 2);
    }
};