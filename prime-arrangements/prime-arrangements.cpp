class Solution {
public:
    int numPrimeArrangements(int n) {
        
        long permutations = 1;
        
        int primeCount = 0, overflow = 1'000'000'007;
        
        // find primes from 0 to n
        vector<bool> notPrime(n+1, false);
        
        notPrime[0] = true;
        notPrime[1] = true;
        
        for (int i = 2; i * i <= n; ++i) {
            
            // check if i is prime
            if (notPrime[i] == false) {
                
                // update all multiples of i
                for (int j = i * i; j <= n; j += i) {
                        
                    notPrime[j] = true;
                }
            }
        }
        
        // count primes from 0 to n
        for (bool b : notPrime) { if (b == false) { ++primeCount; } }
        
        // factorial of prime numbers
        for (int k = 1; k <= primeCount; ++k) {
            
            permutations = (permutations * k) % overflow;
        }
        
        // fatorial of non-prime numbers
        for (int l = 1; l <= (n - primeCount); ++l) {
            
            permutations = (permutations * l) % overflow;
        }
        
        return (int)(permutations);
    }
};