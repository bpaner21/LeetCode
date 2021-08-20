class Solution {
    public int[][] merge(int[][] intervals) {
        
        if (intervals.length <= 1) { return intervals; }
        
        Arrays.sort(intervals, (a,b) -> a[0] - b[0]);
        
        ArrayList<int[]> merge = new ArrayList<>();
        
        int[] back = intervals[0];
        
        merge.add(back);
        
        for (int i = 1; i < intervals.length; ++i) {
            
            if (back[1] >= intervals[i][0]) { back[1] = Math.max(back[1], intervals[i][1]); }
            
            else {
                
                back = intervals[i];
                merge.add(back);
            }
        }
        
        return merge.toArray(new int[merge.size()][]);
    }
}