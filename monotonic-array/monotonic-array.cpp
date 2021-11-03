class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        
        if (A.size() <= 2) { return true; }
        
        bool dec = false, inc = false;
        
        for (int i = 1; i < A.size(); ++i) {
            
            if (A[i-1] < A[i]) { inc = true; }
            if (A[i-1] > A[i]) { dec = true; }
        }
        
        return inc && dec ? false : true;
    }
};