class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    void dfs(vector<vector<char>>& board, vector<vector<int>> &vis, int r, int c, int &n, int &m){
        vis[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] == 1 || board[nr][nc] == 'X') continue;

            dfs(board,vis,nr,nc,n,m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && vis[i][0] == 0){
                dfs(board,vis,i,0,n,m);
            }

            if(board[i][m - 1] == 'O' && vis[i][m - 1] == 0){
                dfs(board,vis,i,m-1,n,m);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O' && vis[0][i] == 0){
                dfs(board,vis,0,i,n,m);
            }

            if(board[n - 1][i] == 'O' && vis[n - 1][i] == 0){
                dfs(board,vis,n-1,i,n,m);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0) board[i][j] = 'X';
            }
        }

    }
};