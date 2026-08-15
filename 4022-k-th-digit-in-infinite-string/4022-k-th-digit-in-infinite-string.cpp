class Solution {
public:
    int kthDigit(long long k) {
        int d = 1;
        long long cnt = 9;

        while(true){
            long long x = 1ll * d * cnt;
            if(k <= x) break;
            k -= x;
            d++;
            cnt *= 10;
        }
        long long x = pow(10,d-1) - 1;
        long long b = (k + d - 1) / d;
        long long num = x + b;
        long long block = num / 10;
        
        int y = num % 10 + 1;
        
        int dec = block % 2;
        if(dec){
            block++;
            num = block * 10 - y;
        }

        int c = (k % d == 0) ? d : k % d;

        string s = to_string(num);
        return s[c - 1] - '0';

    }
};