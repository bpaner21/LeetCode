class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        // if the first characters do not match,
        // there is no way to make typed = name
        if (name[0] != typed[0]) { return false; }
        
        int n = 1;
        
        for (int t = 1; t < typed.size(); ++t) {
            
            if (n < name.size() && name[n] == typed[t]) { ++n; }
            
            // if there is a character in typed that would not be
            // in the same relative position in name
            else if (typed[t] != typed[t - 1]) { return false; }
        }
        
        return n == name.size();
    }
};