class Solution {
    public String kthLargestNumber(String[] nums, int k) {
        
        PriorityQueue<String> pQ = new PriorityQueue<>(
        
            (a, b) -> {
                
                if (a.length() == b.length()) { return a.compareTo(b); }
                
                return Integer.compare(a.length(), b.length());
            }
        );
        
        for (String n : nums) { pQ.add(n); }
        
        while (pQ.size() > k) { pQ.poll(); }
        
        return pQ.poll();
    }
}