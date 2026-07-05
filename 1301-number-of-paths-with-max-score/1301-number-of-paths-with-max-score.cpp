class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        board[n-1][n-1] = '0';
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2)));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = {0,1};
                    continue;
                }
                if(board[i][j] == 'X') {
                    dp[i][j] = {0,0};
                    continue;
                }
                int a = 0, b = 0, c = 0;
                if(i > 0) a = dp[i-1][j][0];
                if(j > 0) b = dp[i][j-1][0];
                if(i > 0 && j > 0) c = dp[i-1][j-1][0];

                int maxi = max({a,b,c});
                long long cnt = 0;
                if(a == maxi && i > 0) cnt = (cnt + dp[i-1][j][1]) % MOD;
                if(b == maxi && j > 0) cnt = (cnt + dp[i][j-1][1]) % MOD;
                if(c == maxi && i > 0 && j > 0) cnt = (cnt + dp[i-1][j-1][1]) % MOD;

                if(cnt == 0) dp[i][j] = {0,0};
                else dp[i][j] = {maxi + board[i][j] - '0', (int)cnt};
            }
        }
        return {dp[n-1][n-1][0], dp[n-1][n-1][1]};
    }
};