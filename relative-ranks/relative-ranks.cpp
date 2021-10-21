class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        
        vector<string> ranks(n, "");
        
        vector<pair<int, int>> rS;
        
        for (int i = 0; i < n; ++i) {
            
            rS.push_back(make_pair(score[i], i));
        }
        
        sort(rS.begin(), rS.end(), greater<>());
        
        for (int j = 0; j < n; ++j) {
            
            int place = rS[j].second;
            
            ranks[place] = to_string(j + 1);
            
            if (j == 0) { ranks[place] = "Gold Medal"; }
            if (j == 1) { ranks[place] = "Silver Medal"; }
            if (j == 2) { ranks[place] = "Bronze Medal"; }
        }
        
        return ranks;
    }
};