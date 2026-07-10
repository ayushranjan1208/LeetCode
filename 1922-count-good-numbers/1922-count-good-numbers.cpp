class Solution {
public:
    const int MOD = 1e9 + 7;
    long long Mypow(long long x, long long n){
        if(n == 0) return 1;

        if(n % 2 == 0){
            return Mypow((x * x) % MOD, n/2);
        }

        return (x * Mypow(x , n - 1)) % MOD;
    }
    int countGoodNumbers(long long n) {
        long long a = (n + 1) / 2, b = n / 2;

        return (Mypow(5,a) * Mypow(4,b)) % MOD;
    }
};