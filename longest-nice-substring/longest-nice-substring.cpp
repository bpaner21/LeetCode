class Solution {
public:
    string longestNiceSubstring(string s) {
        
        if (s.size() < 2) { return ""; }
        
        unordered_set<char> set;
        
        for (char c : s) { set.insert(c); }
        
        for (int i = 0; i < s.size(); ++i) {
            
            if (set.find(tolower(s[i])) != set.end() &&
                    set.find(toupper(s[i])) != set.end()) { continue; }
            
            string a = longestNiceSubstring(s.substr(0, i));
            
            string b = longestNiceSubstring(s.substr(i+1));
            
            return a.size() >= b.size() ? a : b;
        }
        
        return s;
    }
};