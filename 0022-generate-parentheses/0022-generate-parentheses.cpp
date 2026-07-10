class Solution {
public:
    void fun(vector<string> &ans, string &s, int open, int close){
        if(close == 0 && open == 0){
            ans.push_back(s);
            return;
        }

        if(open){
            s.push_back('(');
            fun(ans,s,open - 1,close);
            s.pop_back();
        }

        if(close > open){
            s.push_back(')');
            fun(ans,s,open,close - 1);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        fun(ans,s,n,n);
        return ans;
    }
};