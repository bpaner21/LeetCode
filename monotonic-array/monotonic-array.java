class Solution {
    public boolean isMonotonic(int[] A) {
        
        if (A.length <= 2) { return true; }
        
        boolean inc = false, dec = false;
        
        for (int i = 1; i < A.length; ++i) {
            
            if (A[i-1] < A[i]) { inc = true; }
            if (A[i-1] > A[i]) { dec = true; }
        }
        
        return inc && dec ? false : true;
    }
}