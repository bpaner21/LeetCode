class TopVotedCandidate {
    
    private HashMap<Integer, Integer> leadAtTime = new HashMap();
    
    private int[] times;

    public TopVotedCandidate(int[] persons, int[] times) {
        
        this.times = times;
        
        int lead = Integer.MIN_VALUE;
        
        HashMap<Integer, Integer> candidateVotes = new HashMap();
        
        for (int i = 0; i < times.length; ++i) {
            
            candidateVotes.put(persons[i], candidateVotes.getOrDefault(persons[i], 0) + 1);
            
            if (i == 0 || candidateVotes.get(persons[i]) >= candidateVotes.get(lead)) { lead = persons[i]; }
            
            leadAtTime.put(times[i], lead);
        }
    }
    
    public int q(int t) {
        
        int left = 0, right = times.length - 1, mid;
        
        while (left < right) {
            
            mid = left + ((right - left) / 2) + 1;
            
            if (times[mid] <= t) {
                
                left = mid;
            }
            else {
                
                right = mid - 1;
            }
        }
        
        return leadAtTime.get(times[left]);
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */