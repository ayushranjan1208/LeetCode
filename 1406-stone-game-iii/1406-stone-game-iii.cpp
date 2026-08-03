class Solution {
public:
    vector<int> dp;
    int fun(vector<int> &v, int i, int &n){
        if(i >= n) return 0;

        if(dp[i] != -1e9) return dp[i];

        int f2 = fun(v, i + 2, n);
        int f3 = fun(v, i + 3, n);
        int f4 = fun(v, i + 4, n);
        
        int ans = v[i] + min(f2, min(f3, f4));
        
        if(i + 1 < n){
            int f5 = fun(v, i + 5, n);
            ans = max(ans, v[i] + v[i + 1] + min(f3, min(f4, f5)));
            
            if(i + 2 < n){
                int f6 = fun(v, i + 6, n);
                ans = max(ans, v[i] + v[i + 1] + v[i + 2] + min(f4, min(f5, f6)));
            }
        }
        
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sum = accumulate(stoneValue.begin(),stoneValue.end(),0);

        dp.assign(n,-1e9);

        int alice = fun(stoneValue,0,n);
        int bob = sum - alice;

        if(alice > bob) return "Alice";
        else if(bob > alice) return "Bob";
        return "Tie";
    }
};