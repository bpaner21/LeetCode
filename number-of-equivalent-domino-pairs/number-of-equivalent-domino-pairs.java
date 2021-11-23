class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        
        HashMap<Integer, Integer> map = new HashMap();
        
        int count = 0;
        
        for (int[] d : dominoes) {
            
            int aB = d[0] >= d[1] ? (d[0] * 10) + d[1] : (d[1] * 10) + d[0];
            
            if (map.containsKey(aB)) { count += map.get(aB); }
            
            map.merge(aB, 1, Integer::sum);
        }
        
        return count;
    }
}