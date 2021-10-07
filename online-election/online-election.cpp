class TopVotedCandidate {
private:
    map<int, int> leadAtTime {};
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        
        int lead = INT_MIN;
        
        unordered_map<int, int> CandidateVotes;
        
        for (int i = 0; i < times.size(); ++i) {
            
            ++CandidateVotes[persons[i]];
                                     
            lead = (CandidateVotes[persons[i]] >= CandidateVotes[lead]) ? persons[i] : lead;
            
            leadAtTime[times[i]] = lead;
        }
    }
    
    int q(int t) {
        
        // use map::upper_bound to find the first time AFTER t
        // then go back by one index and return that value
        // this ensures that the returned value comes from the last recorded time <= t
        
        return (--leadAtTime.upper_bound(t))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */