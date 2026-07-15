class Solution {
public:
    bool check(vector<vector<char>> &board, int r, int c, char ch){
        int st_r = (r/3) * 3;
        int st_c = (c/3) * 3;

        for(int i = 0; i <= 8; i++){
            if(board[i][c] == ch || board[r][i] == ch) return false;
        }

        for(int i = st_r; i < st_r + 3; i++){
            for(int j = st_c; j < st_c + 3; j++){
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }
    bool fun(vector<vector<char>> &board, int r, int c){
        if(r == 9) return true;

        int nr = (c == 8) ? r + 1 : r;
        int nc = (c + 1) % 9;

        if(board[r][c] != '.') return fun(board,nr,nc);

        for(char i = '1'; i <= '9'; i++){
            if(check(board,r,c,i)){
                board[r][c] = i;
                if(fun(board,nr,nc)) {
                    return true;
                }
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(board,0,0);
    }
    
};