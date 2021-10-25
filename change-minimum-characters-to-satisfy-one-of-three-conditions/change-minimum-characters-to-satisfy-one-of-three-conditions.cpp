class Solution {
public:
    int minCharacters(string a, string b) {
        
        int sizeA = a.length(), sizeB = b.length(), 
        
                maxC = sizeA + sizeB, minC = maxC;
        
        int countA[26] {0}, countB[26] {0};
        
        
        for (int i = 0; i < sizeA; ++i) { ++countA[a[i] - 'a']; }
        
        for (int j = 0; j < sizeB; ++j) { ++countB[b[j] - 'a']; }
        
        
        for (int k = 0; k < 26; ++k) {
            
            // check if minimum number of changes is 
            // a.length() + b.length() - most common letter (condition 3)
            minC = std::min(minC, maxC - countA[k] - countB[k]);
            
            // calculate prefix sum of the letters in a and b,
            // starting from the letter 'b'
            if (k > 0) {
                
                countA[k] += countA[k - 1];
                    
                countB[k] += countB[k - 1];
            }
            
            // using the prefix sums, check if minimum number of changes is either
            //
            // (a.length() - total letters in a) + total letters in b : a < b (condition 1)
            // or
            // (b.length() - total letters in b) + total letters in a : a > b (condition 2)
            //
            // for every letter up to 'y'(changing every letter to 'z' would already be considered under condition 3)
            if (k < 25) {
                
                minC = std::min(minC, sizeA - countA[k] + countB[k]);
                
                minC = std::min(minC, sizeB - countB[k] + countA[k]);
            }
        }
        
        return minC;
    }
};

/*

1. Every letter in a is strictly less than every letter in b in the alphabet.
2. Every letter in b is strictly less than every letter in a in the alphabet.
3. Both a and b consist of only one distinct letter.

1. every letter in a < every letter in b, minimum is (a.length() - total changed letters in a) + total changed letters in b

2. every letter in a > every letter in b, minimum is (b.length() - total changed letters in b) + total changed letters in a

3. minimum is a.length() + b.length() - most common letter between a and b
*/