class Solution {
    public int numFriendRequests(int[] ages) {
        
        int requests = 0;
        
        int ageCount[] = new int[121];
        
        for (int a : ages) {
            
            ++ageCount[a];
        }
        
        for (int x = 15; x <= 120; ++x) {
            
            for (int y = ((x / 2) + 7) + 1; y <= x; ++y) {
                
                int isSame = x == y ? 1 : 0;
                
                requests += ageCount[y] * (ageCount[x] - isSame);
            }
        }
        
        return requests;
    }
}

/*

2. age[x] < age[y]

3. age[x] < 100 && 100 < age[y]

x cannot make request to anybody older

---

age[y] <= 0.5 * age[x] + 7

age[x] >= (age[y] * 2) - 7

age x cannot make request to age f(x) or lower

x, f(x)
1, 7.5
2, 8
3, 8.5
4, 9
5, 9.5
6, 10
7, 10.5
8, 11
9, 11.5
10, 12
11, 12.5
12, 13
13, 13.5
14, 14

age 1 - 14 cannot make requests

age 15+ can make requests anyone older than f(x)

x, f(x)
15, 14.5
16, 15
...
120, 67

*/