class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        if (nums.size() == 0) { return ""; }
        if (nums.size() == 1) { return to_string(nums[0]); }
        
        vector<string> sN;
        
        for (int i : nums) { sN.push_back(to_string(i)); }
        
        sort (sN.begin(), sN.end(), [](auto i, auto j){ return i+j > j+i; });
        
        // if nums has 0 as its only value, return "0"
        if (sN[0] == "0") { return "0"; }
        
        string s = "";
        
        for (string k : sN) { s += k; }
        
        return s;
    }
};