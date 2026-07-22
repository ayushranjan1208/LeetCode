class Solution {
public:
    vector<bool> isPrime;
    int sieve(int n){
        if(n < 2) return 0;
        isPrime[0] = 0;
        isPrime[1] = 0;
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(isPrime[i]){
                cnt++;
                for(int j = i; j < n; j += i) isPrime[j] = false;
            }
        }
        return cnt;
    }
    int countPrimes(int n) {
        isPrime.assign(n,1);
        return sieve(n);
    }
};