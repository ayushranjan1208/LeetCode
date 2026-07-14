class Solution {
public:
    bool checkPal(string &s,int i, int j){
        if(i > j) return true;

        return (s[i] == s[j]) && checkPal(s,i + 1, j - 1);

    }
    void fun(vector<vector<string>> &ans, vector<string> &vs, string &s, int ind){
        if(ind == s.size()){
            ans.push_back(vs);
            return;
        }

        string temp = "";

        for(int i = ind; i < s.size(); i++){
            temp += s[i];
            if(checkPal(s,ind,i)){
                vs.push_back(temp);
                fun(ans,vs,s,i + 1);
                vs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vs;

        fun(ans,vs,s,0);
        return ans;
    }
};