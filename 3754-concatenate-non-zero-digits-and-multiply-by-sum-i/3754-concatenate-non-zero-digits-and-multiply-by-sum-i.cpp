class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        long long sum = 0;
        int x = 1;
        while(n != 0){
            int d = n % 10;
            sum += d;
            n /= 10;
            if(d != 0){
                ans = d * x + ans;
                x *= 10;
            }
        }
        return ans * sum;
    }
};