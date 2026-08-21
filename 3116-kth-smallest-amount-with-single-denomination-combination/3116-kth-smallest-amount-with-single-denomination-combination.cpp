class Solution {
public:
    long long LCM(long long a, long long b){
        return (a * b) / __gcd(a,b);
    }
    bool check(long long val, vector<int> &c, int k){
        int n = c.size();
        long long cnt = 0;
        for(int i = 1; i < (1 << n); i++){
            int bitCnt = 0;
            long long lcm = 1;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    lcm = LCM(lcm, c[j]);
                    bitCnt++;
                }
            }
            if(bitCnt % 2){
                cnt += (val / lcm);
            }
            else{
                cnt -= (val / lcm);
            }
        }

        return cnt >= k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1, hi = 1e12;
        long long ans = 0;
        while(lo <= hi){
            long long mid = (lo + hi) / 2;
            if(check(mid,coins,k)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return ans;
    }
};