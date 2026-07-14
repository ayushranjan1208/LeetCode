class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    int n,m;
    bool dfs(vector<vector<char>> &board, string &word, int r, int c, int k){
        if(k == word.size()) return true;
        if(r < 0 || r >= n || c < 0 || c >= m || board[r][c] == '?') return false;

        if(board[r][c] != word[k]) return false;

        char ch = board[r][c];
        board[r][c] = '?';

        bool ans = 0;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            ans |= dfs(board,word,nr,nc,k+1);
            if(ans) break;
        }

        board[r][c] = ch;

        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    bool found = dfs(board,word,i,j,0);
                    if(found) return true;
                }
            }
        }
        return false;
    }
};