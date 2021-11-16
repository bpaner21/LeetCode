class Solution {
    public boolean hasAllCodes(String s, int k) {
        
        HashSet<String> codes = new HashSet();
        
        for (int i = 0; i < s.length() - k + 1; ++i) {
            
            codes.add(s.substring(i, i + k));
        }
        
        return (codes.size() == Math.pow(2, k));
    }
}