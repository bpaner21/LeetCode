class Solution {
    public int minSetSize(int[] arr) {
        
        HashMap<Integer, Integer> map = new HashMap();
        int minSet = 0, count = 0;
        
        // count occurrence of all integers in array
        for (int a : arr) {
            
            map.merge(a, 1, Integer::sum);
        }
        
        // java priority queue defaults to min priority
        // use custom comparator for max priority sorting
        PriorityQueue<Integer> q = new PriorityQueue<Integer>(map.size(), (a, b) -> b - a);
        
        // push occurence into priority queue
        map.forEach((key, value) -> q.add(value));
        
        // greedily remove integers until
        // array is at least half its original size
        while (count * 2 < arr.length) {
            
            ++minSet;
            count += q.poll();
        }
        
        return minSet;
    }
}