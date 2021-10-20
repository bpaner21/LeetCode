class Solution {
public:
    struct numStringCompare{
        
      bool operator() (string& b, string& a) {
          
          if (a.size() == b.size()) { return a < b; }
          
          return a.size() < b.size();
      }  
        
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string, vector<string>, numStringCompare> pQ;
        
        for (string& n : nums) { pQ.push(n); }
        
        while (pQ.size() > k) { pQ.pop(); }
        
        return pQ.top();
    }
};