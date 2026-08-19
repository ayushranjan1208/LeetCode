class Solution {
public:
    int fun(int l, int r, vector<int> &pre, vector<vector<int>> &dp){
        if(l >= r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for(int i = l; i <= r - 1; i++){
            int sumL = pre[i + 1] - pre[l];
            int sumR = pre[r + 1] - pre[i + 1];

            if(sumL <= sumR){
                ans = max(ans, sumL + fun(l, i, pre, dp));
            }
            if(sumL >= sumR){
                ans = max(ans, sumR + fun(i + 1, r, pre, dp));
            }
            
        }

        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pre(n + 1, 0);

        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + stoneValue[i];
        }

        // Greedy OR DP?
        vector<vector<int>> dp(n,vector<int>(n, -1));
        return fun(0,n - 1, pre,dp);
    }
};