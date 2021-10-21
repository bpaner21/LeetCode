class Solution {
    public String[] findRelativeRanks(int[] score) {
        
        int n = score.length;
        
        int rS[][] = new int[n][2];
        
        String ranks[] = new String[n];
        
        for (int i = 0; i < n; ++i) {
            
            rS[i][0] = score[i];
            rS[i][1] = i;
        }
        
        Arrays.sort(rS, (a, b) -> (b[0] - a[0]));
        
        for (int j = 0; j < n; ++j) {
            
            int place = rS[j][1];
            
            ranks[place] = "" + (j + 1);
            
            if (j == 0) { ranks[place] = "Gold Medal"; }
            if (j == 1) { ranks[place] = "Silver Medal"; }
            if (j == 2) { ranks[place] = "Bronze Medal"; }
        }

        return ranks;
    }
}