class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;

        int c = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') c++;
            else c--;

            if((c == 1 && s[i] == '(') || (c == 0 && s[i] == ')')) continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};