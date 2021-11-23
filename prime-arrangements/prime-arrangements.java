class Solution {
    public int numPrimeArrangements(int n) {
        
        long permutations = 1;
        
        int primeCount = 0;
        
        boolean notPrime[] = new boolean[n+1];
        
        notPrime[0] = true;
        notPrime[1] = true;
        
        // find primes from 1 to n
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
        for (boolean b : notPrime) { if (b == false) { ++primeCount; } }
        
        // factorial of prime numbers
        for (int k = 1; k <= primeCount; ++k) {
            
            permutations = (permutations * k) % 1_000_000_007;
        }
        
        // fatorial of non-prime numbers
        for (int l = 1; l <= (n - primeCount); ++l) {
            
            permutations = (permutations * l) % 1_000_000_007;
        }
        
        return (int)(permutations);
    }
}