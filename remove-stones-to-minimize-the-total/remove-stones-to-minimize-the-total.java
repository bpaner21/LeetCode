class Solution {
    public int minStoneSum(int[] piles, int k) {
        
        PriorityQueue<Integer> pQ = new PriorityQueue<>((a, b) -> (b - a));
        
        int sum = 0;
        
        for (int p : piles) {
            
            sum += p;
            
            pQ.add(p);
        }
        
        while (k > 0) {
            
            int temp = pQ.poll();
            
            sum -= (temp / 2);
            
            pQ.add(temp - (temp / 2));
            
            --k;
        }
        
        return sum;
    }
}