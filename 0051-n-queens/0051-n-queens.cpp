class Solution {
public:
    vector<string> generateAns(vector<int> &pos, int n){
        vector<string> ans(n);

        for(int i = 0; i < n; i++){
            string s(n,'.');
            s[pos[i]] = 'Q';
            ans[i] = s;
        }
        return ans;
    }
    // bool checkPos(vector<int> &pos){
    //     int r = pos.size() - 1;

    //     int d1 = pos[r], d2 = pos[r], st = pos[r];

    //     for(int i = r - 1; i >= 0; i--){
    //         if(pos[i] == --d1 || pos[i] == ++d2 || pos[i] == st) return false;
    //     }
    //     return true;
    // }
    void fun(vector<vector<string>> &ans, vector<int> &pos, int row, int n, vector<int> &diag1, vector<int> &diag2, vector<int> &straight){
        if(row == n){
            vector<string> vs = generateAns(pos,n);
            ans.push_back(vs);
            return;
        }

        for(int i = 0; i < n; i++){
            if(diag1[row - i + n - 1] || diag2[row + i] || straight[i]) continue;
            pos.push_back(i);
            diag1[row - i + n - 1] = 1;
            diag2[row + i] = 1;
            straight[i] = 1;
            fun(ans,pos,row + 1,n,diag1,diag2,straight);
            pos.pop_back();
            diag1[row - i + n - 1] = 0;
            diag2[row + i] = 0;
            straight[i] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos;

        vector<int> diag1(2*n,0), diag2(2*n,0), straight(n,0);
        fun(ans,pos,0,n,diag1,diag2,straight);

        return ans;
    }
};