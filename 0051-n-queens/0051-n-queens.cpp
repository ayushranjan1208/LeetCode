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
    bool checkPos(vector<int> &pos){
        int r = pos.size() - 1;

        int d1 = pos[r], d2 = pos[r], st = pos[r];

        for(int i = r - 1; i >= 0; i--){
            if(pos[i] == --d1 || pos[i] == ++d2 || pos[i] == st) return false;
        }
        return true;
    }
    void fun(vector<vector<string>> &ans, vector<int> &pos, int row, int n){
        if(row == n){
            vector<string> vs = generateAns(pos,n);
            ans.push_back(vs);
            return;
        }

        for(int i = 0; i < n; i++){
            pos.push_back(i);
            if(checkPos(pos)){
                fun(ans,pos,row + 1,n);
            }
            pos.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos;
        fun(ans,pos,0,n);

        return ans;
    }
};