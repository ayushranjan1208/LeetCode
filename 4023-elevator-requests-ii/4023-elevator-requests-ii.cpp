class Solution {
public:
    long long fun(int pos, int lo, int hi, int n, vector<int> &r, vector<vector<vector<long long>>> &dp){
        if(lo == -1 && hi == n) return 0;

        if(dp[lo + 1][hi][pos] != -1) return dp[lo + 1][hi][pos];

        int cur = (pos == 0) ? lo + 1 : hi - 1;

        long long take_up = 1e18, take_down = 1e18;
        int e = (lo >= 0 ? lo + 1 : 0) + (hi < n ? n - hi : 0);
        if(lo >= 0){
            take_down = (e * 1ll * (r[cur] - r[lo])) + fun(0, lo - 1, hi, n, r, dp);
        }
        if(hi < n){
            take_up = e * 1ll * (r[hi] - r[cur]) + fun(1, lo, hi + 1, n, r, dp);
        }

        return dp[lo + 1][hi][pos] = min(take_up, take_down);
    }
    long long elevatorRequests(int x, int start, vector<int>& r) {
        int n = r.size();
        sort(r.begin(), r.end());
        int id = lower_bound(r.begin(), r.end(), start) - r.begin();
        long long ans = 1e18;

        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2, -1)));
        if(id < n && r[id] == start){
            ans = fun(0, id - 1, id + 1, n, r, dp);
        }
        else{
            if(id < n){
                ans = n * 1ll * (r[id] - start) + fun(0 ,id - 1, id + 1, n, r, dp);
            }
            if(id > 0){
                ans = min(ans, n * 1ll * (start - r[id-1]) + fun(1, id - 2, id, n, r, dp));
            }
        }

        return ans;
    }
};